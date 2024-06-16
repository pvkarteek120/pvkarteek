from machine import Pin, PWM
from utime import sleep

# Define the GPIO pin for the buzzer
buzzer = PWM(Pin(15))

# Define frequencies for musical notes (C, D, E, F, G, A, B)
notes = {
    "C4": 262,
    "D4": 294,
    "E4": 330,
    "F4": 349,
    "G4": 392,
    "A4": 440,
    "B4": 494,
    "C5": 523
}

# Define a simple melody (Twinkle Twinkle Little Star)
melody = [
    ("C4", 0.5), ("C4", 0.5), ("G4", 0.5), ("G4", 0.5),
    ("A4", 0.5), ("A4", 0.5), ("G4", 1.0),
    ("F4", 0.5), ("F4", 0.5), ("E4", 0.5), ("E4", 0.5),
    ("D4", 0.5), ("D4", 0.5), ("C4", 1.0)
]

def play_tone(frequency, duration):
    if frequency == 0:
        sleep(duration)
    else:
        buzzer.freq(frequency)
        buzzer.duty_u16(32768)  # 50% duty cycle
        sleep(duration)
        buzzer.duty_u16(0)      # Turn off buzzer
        
def play_melody(melody):
    for note, duration in melody:
        play_tone(notes[note], duration)
        sleep(0.1)  # Short pause between notes

# Play the melody
play_melody(melody)
