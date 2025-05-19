# 💻 Retirement & Loan Payoff Calculator (C++)

A console-based financial calculator that helps users:

- Estimate **total retirement savings** based on starting age, monthly contributions, and investment return rates.
- Calculate how many months it will take to **pay off a loan**, and how much time can be saved by increasing monthly payments.

This project was originally written in C++ and run through a terminal interface.

---

## 📂 Features

- 📆 Compare retirement savings starting at two different ages
- 💼 Display compound growth and total interest earned
- 💸 Calculate time to pay off a loan with monthly interest
- ⚡ Suggest how much faster a loan could be paid off by adding $15/month
- 🔁 Re-prompts for new calculations until the user quits

---

## 🧠 Logic Overview

### 🏦 Retirement Estimator:
- Compound interest calculated monthly:
  \[
  \text{balance} += \text{balance} \times r + \text{monthly contribution}
  \]
  where \( r = \frac{\text{annual return rate}}{1200} \)

- Compares two user-defined starting ages and reports potential missed gains

---

### 💸 Loan Payoff Calculator:
- Uses the loan payoff formula:
  \[
  n = \frac{\log(M) - \log(M - r \cdot P)}{\log(1 + r)}
  \]
  where:
  - \( M \) = monthly payment
  - \( P \) = principal
  - \( r \) = monthly interest rate

- Shows how many months and years until payoff
- Shows how many months can be saved by paying $15 extra/month

---

## 🛠 How to Compile and Run

Make sure you have `g++` installed.

### 🧪 To compile:

```bash
make compile

To Run:
make run

To Clean:
make clean

🎓 Educational Purpose

This project was developed as part of a computer science course (CPSC 1061).
It demonstrates structured programming, input validation, loops, functions, and basic financial mathematics.
