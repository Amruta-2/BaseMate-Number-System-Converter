# 🔢BaseMate-Number-System-Converter

This project is a **BaseMate-Number-System-Converter** written in the C programming language. It provides an interactive, menu-driven interface to convert numbers between **Binary**, **Decimal**, **Octal**, and **Hexadecimal** systems with optional **step-by-step explanations** and **conversion history logging**.

---

## 🚀 Features

- ✅ Convert between:
  - Decimal ➜ Binary / Octal / Hexadecimal
  - Binary ➜ Decimal / Hexadecimal
  - Octal ➜ Decimal
  - Hexadecimal ➜ Decimal / Binary
- 🔍 Input validation for each number system
- 📜 Step-by-step explanation mode (optional)
- 🕒 Logs each conversion with timestamp in `history.txt`
- 📂 View and clear history
- 🧱 Modular code (logic separated from UI)
- 📚 Beginner-friendly and well-commented

---

## 🗂️ Project Structure

```
NumberSystemConverter/
│
├── main.c              # Main menu interface
├── logic.c             # All conversion logic and utility functions
├── logic.h             # Header file with function declarations
├── history.txt         # Auto-generated file storing conversion history
└── README.md           # Project documentation
```

---

## 🧠 How It Works

Each conversion option (like Decimal ➜ Binary) is handled by:
1. A **prompt function** that:
   - Accepts and validates user input
   - Asks whether to show step-by-step explanation
2. A **conversion function** that:
   - Performs the actual logic
   - Shows explanation if enabled
   - Logs the result to `history.txt`

---

## 🛠️ Compilation & Execution

### 🖥️ Compile

```bash
gcc main.c logic.c -o converter
```

### ▶️ Run

```bash
./converter
```

On Windows:
```bash
converter.exe
```

---

## 📥 Sample Menu (UI Example)

```text
🔢 Welcome to Number System Converter

1. Decimal ➜ Binary
2. Decimal ➜ Octal
3. Decimal ➜ Hexadecimal
4. Binary ➜ Decimal
5. Octal ➜ Decimal
6. Hexadecimal ➜ Decimal
7. Binary ➜ Hexadecimal
8. Hexadecimal ➜ Binary
9. View Conversion History
10. Clear Conversion History
0. Exit
Enter your choice:
```

---

## 🧪 Example Conversion

- Input: `15`  
- Mode: Decimal ➜ Binary  
- Step-by-step: Yes  

```text
Step 1: 15 / 2 = 7, Remainder = 1  
Step 2: 7 / 2 = 3, Remainder = 1  
Step 3: 3 / 2 = 1, Remainder = 1  
Step 4: 1 / 2 = 0, Remainder = 1  

Binary of 15 is: 1111
```

---

## 🧾 Conversion History (`history.txt`)

Each conversion is logged like:

```
15 ➜ 1111 | Base 10 ➜ 2 | 2025-07-13 17:26:40
A2F ➜ 101000101111 | Base 16 ➜ 2 | 2025-07-13 17:28:03
```

---

## 📌 Requirements

- A C compiler (e.g., GCC, Clang)
- Works on Windows, Linux, macOS

---

## 👩‍💻 Author

**Amruta Pradip Patil**  
🎓 Final Year CSE
