# 🏦 Bank System Using OOP

> A robust, console-based banking management application built with Object-Oriented Programming principles and a unique binary permission system.

![Project Status](https://img.shields.io/badge/Status-Active-green)
![Language](https://img.shields.io/badge/Language-[C++]-blue)
![License](https://img.shields.io/badge/License-MIT-lightgrey)

## 📖 Overview

**Bank System Using OOP** is a comprehensive console application designed to simulate core banking operations. It demonstrates the practical application of Object-Oriented Programming (OOP) concepts such as Encapsulation, Inheritance, and Abstraction.

The system is designed with security and scalability in mind, featuring a custom-built **Bitwise Permission System** to manage user access levels efficiently.

## ✨ Key Features

### 👥 Client Management
* **Add New Customer:** Create new client accounts with unique IDs.
* **Update Customer:** Modify existing client details.
* **Delete Customer:** Remove client records safely from the system.
* **View Client List:** Display a formatted list of all active clients.

### 💼 User & Admin Management
* **User Management:** Create and manage system users (bank staff).
* **Granular Permissions:** Assign specific roles and access rights to different users.

### 💰 Transactions
* **Deposits:** Add funds to client accounts.
* **Withdrawals:** deduct funds with balance validation.
* **Total Balances:** View the total liquidity held across all clients.

### 🔐 Security Highlight: Binary Permission System
This project utilizes a **Bitwise Permission System** to handle user authorization. instead of storing long strings of roles, permissions are calculated using binary flags. This allows for:
* **Efficiency:** Permissions are stored as a single integer.
* **Flexibility:** Multiple permissions can be combined using bitwise `OR` operations.

**Example Logic:**
* `1` (001): Show List
* `2` (010): Add Client
* `4` (100): Delete Client
* *User with value `3` (011) can Show List AND Add Client.*

## 🛠️ Technical Implementation

This project is built using **[C++]** Language.
* **OOP Principles:** Heavy use of classes to represent Clients, Users, and Transactions.
* **Data Persistence:** [Files].txt
* **Algorithm:** Custom algorithms for handling the binary permission calculations.

## 🚀 Future Roadmap

I am actively working on improving this project. The current roadmap includes:

- [ ] **Web Migration:** converting the core logic into a Web API (Backend) and creating a Frontend interface.
- [ ] **Database Integration:** Moving from file-based storage to SQL.
- [ ] **Transaction History:** Adding a log for every financial movement.
- [ ] **Interest Calculation:** Implementing savings account logic.

## 🙏 Acknowledgment

Special thanks and deep appreciation to **Dr. Mohammed Abu Hadhoud**,
for his invaluable teaching, continuous support, and outstanding guidance throughout this project.
This work was inspired and made possible through his educational platform
[Programmingadvices.com](ProgrammingAdvices.com)
,
which was the primary source of learning how to build this system step by step.


## 📬 Contact

<p align="left">
    <a href="https://www.linkedin.com/in/mohammed-ali-alamoudi" target="_blank">
    <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" />
  </a>
  <a href="https://instagram.com/Mo__Ali_77" target="_blank">
    <img src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white" />
  </a>
  <a href="https://x.com/moalialamoudi" target="_blank">
    <img src="https://img.shields.io/badge/Twitter-000000?style=for-the-badge&logo=x&logoColor=white" />
  </a>
  <a href="mailto:alamoudimohammedali@gmail.com">
    <img src="https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white" />
  </a>
</p>