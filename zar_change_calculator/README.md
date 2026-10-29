# ZAR Change Calculator

A South African coin change calculator written in C. 
Inspired by CS50 Week 1 concepts, but built as an original portfolio project using South African currency.

Calculates the minimum number of coins needed for any amount in Rands.

### Concepts Demonstrated
- Input validation (finite, non-negative values)
- Handling float errors with `round()` and converting to cents
- Greedy Algorithm
- Arrays and Loops
- Functions in C
- Error handling for SA edge cases (no 1c/2c coins)

### SA Coins Used
`R5 (500c), R2 (200c), R1 (100c), 50c, 20c, 10c, 5c`

## Examples
Change owed in Rands (e.g. 12.50): 4.80

Total change: R4.80
Minimum coins needed: 5


Change owed in Rands (e.g. 12.50): 12.50
Note: 0c left

Total change: R12.50
Minimum coins needed: 4 (R5 x2, R2 x1, 50c x1)


### How to Compile & Run

This project uses the math library, so you MUST link with `-lm`.

Standard C version:
```bash
gcc calculator.c -lm -o calculator
./calculator
