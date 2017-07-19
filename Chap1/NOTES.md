# Cracking The Coding Interview - Chapter 1 - Arrays and Strings

---
## Question 1.1

**Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?**

### Ask Questions

 1. Is the string encoded in ASCII?
 2. Is this a C-style string (ending with ```\0```, and can be operated upon with ```<string>```)?
 3. May I make a copy of the input string?
 4. If I have to do it in place, may I change the contents of the buffer?
 5. How should the function results defined if the string is an empty string?

### Design an Algorithm

 1. Use char flags: set up a Boolean array of 256 elements, each representing an unique character.
 2. Use bit maps: similar to char flags, but more compact since we only use 256 bits (equivalent to 8 32-bit integers). Need to use some bit manipulation.
 3. Use hash maps: for each character, check if it already exists in the key set.
 4. Sort the string.

### Write Pseudocodes

### Write Real Codes

### Test and Fix Bugs

#### Test Cases
 1. Empty string
 2. String with only one char
 3. All-unique char string
 4. All-duplicates string
 5. String with some unique chars and some duplicates

---

## Question 1.2

**Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)**

### Ask Questions

 1. What if the string does not have a proper ending of ```\0```?

### Design an Algorithm

 The algorithm is relatively simple. Simply swap the characters ```myStr[i]``` with ```myStr[strlen (myStr) - i - 1]```, where ```i = 0 .. floor (strlen (myStr) / 2)```.

### Write Pseudocodes

### Write Real Codes

### Test and Fix Bugs

#### Test Cases

---

## Question 1.3

---

## Question 1.4

---

## Question 1.5

---

## Question 1.6

---

## Question 1.7

---

## Question 1.8
