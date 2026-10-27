# Password Strength Checker V2 - C

Real-world password security audit tool built in C - CS50x + Cybersecurity Project.

## Features (V2 Upgrades)
- **Common Password Blacklist:** Blocks top 10 most hacked passwords (password, 123456, qwerty)
- **Entropy & Crack Time Estimator:** Calculates bits of entropy and time to crack (1 billion guesses/sec)
- **Smart Suggestion Engine:** Tells user exactly how to make password STRONG

## How It Works
- Scores 6 points: length 8+, length 12+, uppercase, lowercase, digit, symbol
- Calculates charset size and entropy: entropy = length * log2(charset)
- WEAK (0-2), MEDIUM (3-4), STRONG (5-6)

## Compile & Run
CS50 make requires math library:

```bash
make password_chec# Password Strength Checker V2 - C

Real-world password security audit tool built in C - CS50x + Cybersecurity Project.

## Features (V2 Upgrades)
- **Common Password Blacklist:** Blocks top 10 most hacked passwords (password, 123456, qwerty)
- **Entropy & Crack Time Estimator:** Calculates bits of entropy and time to crack (1 billion guesses/sec)
- **Smart Suggestion Engine:** Tells user exactly how to make password STRONG

## How It Works
- Scores 6 points: length 8+, length 12+, uppercase, lowercase, digit, symbol
- Calculates charset size and entropy: entropy = length * log2(charset)
- WEAK (0-2), MEDIUM (3-4), STRONG (5-6)

## Compile & Run
CS50 make requires math library:

```bash
make password_checker LDLIBS="-lm"
./password_checkerker LDLIBS="-lm"
./password_checker
