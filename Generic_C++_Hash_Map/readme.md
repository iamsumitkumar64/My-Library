# ✅ C++ Generic & Non-Generic Hash Map Library

This project contains a **Generic** and **Non-Generic** implementation of a Hash Map in C++ using a custom Linked List as the underlying structure.

---

## 📁 Folder Structure

```
GENERIC C++ LL/
│
├── generic_libs/
│   ├── header.h       # Generic class declarations
│   └── source.cpp     # Generic class definitions
│
├── non_generic_libs/
│   ├── header.h       # Non-generic declarations
│   └── source.cpp     # Non-generic definitions
│
├── main.cpp           # CLI to test the Hash Map
└── README.md
```

---

## ⚙️ How to Run

> 🔧 Make sure you have `g++` installed (C++11 or above).

### ✅ Compile & Run in one go:

```bash
g++ main.cpp -o main && ./main
```

☝️ **No need to separately compile or link `source.cpp`**. All logic is included via `#include` in `main.cpp`.

---

## 🧠 Switching Between Generic & Non-Generic

Inside `main.cpp`, toggle between the two versions:

```cpp
// #include "./non_generic_libs/header.h" // For Non-Generic
#include "./generic_libs/header.h"        // For Generic
```

🟡 Just comment/uncomment the one you want to use.

---

## ✅ Features

- Templated Hash Map with Linked List chaining
- Automatic rehashing when capacity threshold is hit
- Clean modular code
- Easily switchable between generic and non-generic usage

---

## 📌 Example Usage

```cpp
Hash_map<int, int> obj(size); // Generic usage
```

You can insert, remove, search, or display key-value pairs using a simple menu-driven CLI.

---

## 👨‍💻 Author

**Sumit Birwal**  
💡 Focused on reusable, modular, and scalable C++ libraries.