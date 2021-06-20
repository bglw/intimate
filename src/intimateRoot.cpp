#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncE131.h>
#include "engine/engine.h"

// E1.31 config
#define STRIP_LEN 60
#define STRIP_ID 2
#define UNIVERSE_COUNT 1
// #define DMX_ADDR 1 // 1 91 181 271 361

// We must fit whole strips in each universe. No bridging.
const uint8_t STRIPS_IN_UNIVERSE = 512 / (STRIP_LEN * 3);
const uint16_t START_UNIVERSE = (((STRIP_ID) * STRIP_LEN * 3) / 512) + 2;
// Within the given universe, calculate the DMX address of this fixture
const uint8_t ID_IN_UNIVERSE = ((STRIP_ID - 1) % STRIPS_IN_UNIVERSE) + 1;
const uint16_t DMX_ADDR = (((ID_IN_UNIVERSE - 1) * STRIP_LEN * 3) % 512) + 1;

// Network config
const char ssid[] = "intimate"; // Replace with your SSID
const char passphrase[] = "lemongrass";    // Replace with your WPA2 passphrase

// Animations
Intimate::Engine engine;

// ESPAsyncE131 instance with UNIVERSE_COUNT buffer slots
ESPAsyncE131 e131(UNIVERSE_COUNT);

void setup()
{
    Serial.begin(74880);
    delay(1000);

    Serial.println(F("Intimate node online"));

    engine.setup(DMX_ADDR);
    engine.blank();
    engine.wifi_wait();
    engine.render();

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, passphrase);

    while (WiFi.status() != WL_CONNECTED)
    {
        engine.wifi_wait();
        delay(500);
    }
    
    Serial.println(F("Successfully connected to a network"));
    
    engine.wifi_done();
    delay(1000);
    // Serial.println(WiFi.localIP());

    Serial.println();
    Serial.println(F("---------------------------"));
    Serial.print(F("Total Strip ID:         "));
    Serial.println(STRIP_ID);
    Serial.print(F("Strips Per Universe:    "));
    Serial.println(STRIPS_IN_UNIVERSE);
    Serial.print(F("Universe Strip ID:      "));
    Serial.println(ID_IN_UNIVERSE);
    Serial.print(F("Universe ID:            "));
    Serial.println(START_UNIVERSE);
    Serial.print(F("DMX Address:            "));
    Serial.println(DMX_ADDR);
    Serial.println(F("---------------------------"));
    Serial.println();

    if (e131.begin(E131_MULTICAST, START_UNIVERSE, UNIVERSE_COUNT))
    {
        Serial.println(F("I have my ear out for E1.31"));
        engine.ready();
    }
    else
    {
        Serial.println(F("*** e131.begin failed ***"));
        engine.error();
    }
}

void loop()
{
    if (!e131.isEmpty())
    {
        e131_packet_t packet;
        e131.pull(&packet); // Pull packet from ring buffer

        engine.update(packet.property_values);
    }

    //Intimate::Animations::glitter(engine, engine.primary);

    //engine.step();

    engine.render();
}