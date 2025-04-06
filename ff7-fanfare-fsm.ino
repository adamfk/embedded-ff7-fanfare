#include "src/audio/songs.hpp"
#include "src/audio/SongPlayer.hpp"

const uint8_t frequency_scaler = 2;
SongPlayer player{};

void setup()
{
    delay(500); // seems required for wokwi to not miss the first note

    player.set_song(Ff7FanFare::song, frequency_scaler);
    player.play_from_start(millis());
}

void loop()
{
    player.update(millis());
    delay(5); // lower wokwi simulation CPU usage
}
