# 🏦 Bank Management System (Full OOP)

A robust and secure **Banking Management System** developed in **C++**. This project is a comprehensive demonstration of **Object-Oriented Programming (OOP)**, inheritance, and professional file-based data management.

## 🌟 Key Features

### 🚀 Main Features
- **Client Management**: Add, Delete, Update, and Find clients.
- **User Management**: Multi-user system with different permissions (Admin/User).
- **Transaction System**: Deposit, Withdraw, and Transfer between accounts.
- **Currency Exchange**: Real-time currency conversion and rate updates.
- **Logging System**: Tracks Login/Logout activities and Transfer logs in text files.
- **Data Persistence**: All data is saved and retrieved from `.txt` files.

### 👤 User & Security System
- **Authentication**: Secure login system with `LoginRegister.txt` tracking.
- **Permissions**: Multi-level user access (Admin vs. Regular User) managed via `clsUser.h`.
- **Activity Logs**: Tracks every login/logout and transfer operation in `TransferLog.txt`.

### 💰 Financial Operations
- **Account Management**: Full CRUD operations (Add, Delete, Update, Find) for Clients.
- **Transactions**: Support for Deposits, Withdrawals, and Transfers between accounts with validation.
- **Total Balances**: Real-time calculation of all bank assets.

### 💱 Currency Exchange System
- **Live Rates**: Manage and update currency rates via `Currencies.txt`.
- **Currency Calculator**: Convert between international currencies using `clsCurrency.h` logic.

## 🛠️ Technical Stack
- **Language**: C++
- **Design Pattern**: Object-Oriented Programming (Modular Classes)
- **Data Persistence**: Flat-file database system (`.txt` files).
- **Validation**: Robust input handling through `clsInputValidate.h`.

## 📂 Project Structure (Main Files)
- `Bank.cpp`: The entry point of the application.
- `Bank.slnx`: Visual Studio solution file for easy setup.
- `cls...h`: Logic and UI classes for different system screens.
- `*.txt`: Data files acting as the system's database.

---
*Developed with a focus on clean code and scalable software architecture.*

##### Developed by: AbooodGh 👨‍💻

