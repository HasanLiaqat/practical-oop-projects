# Course Management System

## Objective
Create a course management system that demonstrates practical OOP implementation in C++.

## Concepts Demonstrated
- Classes and Objects
- Constructors (default, parameterized, copy)
- Encapsulation (private data members)
- Member functions
- Conditional logic
- Boolean flags (lab course surcharge)
- Case-insensitive comparison

## Class Design
Class: Course

**Private Members**
- `courseCode` → unique code
- `courseName` → name of course
- `creditHours` → number of credit hours
- `feePerCredit` → fee per credit hour
- `isLab` → boolean flag for lab courses

**Public Functions**
- Constructors (default, parameterized, copy)
- `setCourseCode`, `setCreditHours`, `setIsLab`
- `calculateFee()` → returns total fee (adds Rs.500 if lab)
- `display()` → prints course details
- `isSameAs()` → compares course codes case-insensitively

## Practical Use
- Simulates university courses with optional labs
- Demonstrates fee calculation logic
- Showcases copy constructor and object duplication

## Learning Outcomes
- How to design classes for real-world systems
- Using constructors effectively
- Encapsulation and controlled access
- Writing reusable member functions
