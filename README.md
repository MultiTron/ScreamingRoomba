# 🤖 Screaming Roomba

Ever looked at your silent, emotionless Roomba and thought, *"What if it could scream every time it hit a wall?"*  
Well, wonder no more.

## What Is This?

Screaming Roomba is a two-part project that gives your robotic vacuum a voice—specifically, the voice of someone in existential distress. It screams. When it bumps into things. Like a tiny, doomed banshee on wheels.

## The Guts

### 🧠 Part 1: The ESP8266 (a.k.a. The Pain Sensor)

- Two aluminum plates act as bump sensors.
- When they touch (i.e., when your Roomba crashes into stuff), the ESP8266 detects it.
- It then updates a tiny webpage it hosts, which tells any connected device: *“SCREAM NOW.”*

### 🔊 Part 2: Node.js Server (a.k.a. The Scream Machine)

- Runs on your laptop or any machine that can host Node.js.
- Serves up a fine selection of pre-curated scream sound files.
- The webpage fetches a deliciously painful scream from the server and plays it.

## How It Works (in vibes)

1. Roomba hits a wall.  
2. ESP8266: “OH NO.”  
3. Website: *"Time to panic!"*  
4. Your device: **AAAAAAAAAAAAAA!!!**

## Why?

Because silence is overrated. Because your Roomba deserves a voice.  
Because science.

---

Feel free to fork, tinker, and give your Roomba a full emotional range. Next up: laughter? Whispers? Existential monologues?
