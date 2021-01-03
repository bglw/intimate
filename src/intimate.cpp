#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncE131.h>
#include "engine/engine.h"

// E1.31 config
#define START_UNIVERSE 1
#define UNIVERSE_COUNT 1

// Network config
const char ssid[] = "uhhhh we don't have any"; // Replace with your SSID
const char passphrase[] = "PterraceRoyale";    // Replace with your WPA2 passphrase

// Animations
Intimate::Engine engine;

// ESPAsyncE131 instance with UNIVERSE_COUNT buffer slots
ESPAsyncE131 e131(UNIVERSE_COUNT);

void setup()
{
    Serial.begin(115200);
    delay(3000);

    engine.setup(0);
    engine.blank();

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, passphrase);

    bool wifi_flip = false;
    while (WiFi.status() != WL_CONNECTED)
    {
        engine.wifi_wait();
        delay(500);
    }
    engine.wifi_done();
    delay(2000);
    // Serial.println(WiFi.localIP());

    if (e131.begin(E131_MULTICAST, START_UNIVERSE, UNIVERSE_COUNT))
    {
        Serial.println(F("E1.31 Now Listening"));
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

    Intimate::Animations::glitter(engine, engine.primary);

    engine.render();
}