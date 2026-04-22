# Hospital Management System (OOP)

## 📌 Objective
Design a hospital ward management system using Object-Oriented Programming concepts in C++.

The system supports:
- General patients
- ICU patients
- Dynamic patient management (add, remove, display)

---

## 🧠 Concepts Demonstrated

- Inheritance (Patient → GeneralPatient, ICUPatient)
- Runtime Polymorphism (virtual functions)
- Dynamic Memory Management (new/delete)
- Pointer Arithmetic
- Encapsulation
- Destructor chaining
- Menu-driven program design

---

## 🏗 Class Design

### Base Class: Patient
**Members:**
- name (dynamic char array)
- patientID
- dailyBill

**Functions:**
- treatmentSummary() → virtual
- getDailyBill()
- Virtual destructor

---

### Derived Class: GeneralPatient
**Extra:**
- ward (dynamic char array)

**Overrides:**
- treatmentSummary()

---

### Derived Class: ICUPatient
**Extra:**
- criticalLevel

**Overrides:**
- treatmentSummary()

---

## ⚙ Key Features

### 1. Polymorphism
Using `Patient*` pointers:
- Calls correct `treatmentSummary()` at runtime

### 2. Dynamic Memory
- Patients stored as `Patient**`
- Manual allocation and deallocation

### 3. Destructor Chaining
- Base + derived destructors called automatically

### 4. Pointer Arithmetic
- Iteration using pointer increments instead of indexing

---

## 🧪 Program Modes

### 1. Scripted Mode
- Predefined patients
- Demonstrates system behavior

### 2. User Mode
- Add patients
- Display summaries
- Calculate total billing
- Discharge patients dynamically

---

## ⚠ Important Learnings

- Importance of **virtual destructors**
- Managing memory safely with `new/delete`
- Using base class pointers for polymorphism
- Avoiding memory leaks

---

## 🎯 Learning Outcome

- Built a real-world system using OOP
- Applied inheritance + polymorphism in practice
- Managed dynamic memory manually
- Designed a menu-driven application
