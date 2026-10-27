# Intrusion Detector - Log Analyzer in C
### Project 3 - Harvard CS50x 2026 | Cybersecurity

Real-world SOC Analyst tool built in C to detect brute-force attacks from auth logs.

### What it does
- Reads `auth.log` file line by line
- Counts FAILED vs SUCCESS logins
- Flags suspicious activity (5+ fails = possible attack)
- Displays attacker IP and recommendation to block

### Features
- File I/O in C (`fopen`, `fgets`)
- String parsing (`strstr`)
- Security reporting
- Detects brute-force pattern

### How to run
```bash
gcc log_analyzer.c -o detector
./detector
