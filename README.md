# 💙 **MedSync Pro**  
### *A Modular OOP-Driven Hospital Management Ecosystem*  

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-OOP-blue?style=for-the-badge&logo=c%2B%2B&logoColor=white">
  <img src="https://img.shields.io/badge/Hospital-Management-green?style=for-the-badge">
  <img src="https://img.shields.io/badge/Role--Based-System-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge">
  <br>
  <img src="https://img.shields.io/badge/Built%20with-C%2B%2B17-blue?style=flat-square&logo=c%2B%2B">
  <img src="https://img.shields.io/badge/OOP-Encapsulation%2FPolymorphism%2FInheritance-purple?style=flat-square">
  <img src="https://img.shields.io/badge/Status-Final%20Submission-brightgreen?style=flat-square">
  <img src="https://img.shields.io/badge/Made%20with%20❤️%20in-Egypt-red?style=flat-square">
</p>

---

# 🏷️ **Tags**
`#OOP` · `#C++` · `#HospitalSystem` · `#RoleBasedAccess` · `#FilesHandling` · `#UniversityProject` · `#Classes` · `#Encapsulation` · `#Polymorphism` · `#DataSecurity` · `#UIFlow`

---

# 📌 **Summary**

**MedSync Pro** is a full OOP-based hospital management ecosystem built in C++.  
It simulates real hospital workflows across three roles: **Doctor, Patient, and Admin**, using fully separated class structures and a persistent file-based storage system.

### ✔️ **What it is**  
A modular hospital management application that assigns users to different interfaces based on their role.

### ✔️ **What it offers**
- Secure login system with role detection  
- Doctor scheduling + patient assignment  
- Appointment booking pipeline  
- Prescription management  
- Profile editing for all roles  
- Admin tools for request handling & patient removal  
- Persistent file saving for all user data  

### ✔️ **How it works**
Users log in or register → program loads their stored data → opens the correct class window → user interacts with role-specific features → changes automatically save back to external files.

### ✔️ **What I learned**
- Deep practical experience in **OOP structure & separation**
- Using **encapsulation** to secure user data
- Applying **inheritance and polymorphism** to reduce redundancy
- Managing **file I/O** for persistent storage  
- Designing multi-role architectures
- Building complete user flows  
- Debugging large structured systems  
- The importance of code organization & documentation  

---

# 🧠 **Object-Oriented Programming Breakdown**

MedSync Pro heavily uses OOP concepts to keep the system clean, expandable, and maintainable.

### 🔹 **Classes Architecture**
- **User (Base Class)**  
  Stores shared data (name, password, age, etc.)

- **Doctor : public User**  
- **Patient : public User**  
- **Admin : public User**

Each subclass overrides and extends functionalities using polymorphism.

---

### 🔹 **Encapsulation & Data Security**

Sensitive data (passwords, user info) are kept private.  
Interaction happens through controlled setter/getter functions.

Examples:
- Private attributes for all personal info  
- Validation before editing data  
- File-based saving with controlled access  

---

### 🔹 **Functions & Responsibilities**

- Constructors for initialization  
- Update/view functions  
- Scheduling functions  
- Prescription handling  
- Appointment request management  
- File read/write operations  

Everything is modular, structured, and extendable.

---

# 🧩 **Role Breakdown & Class Responsibilities**

## 🩺 **Doctor Class**
- Select specialty  
- Set working hours  
- View schedule  
- Check assigned patients  
- Remove appointments  
- Edit profile  
- Add prescriptions  
- Save changes to file automatically  

---

## 🧑‍🤝‍🧑 **Patient Class**
- View & update profile  
- Book appointments by specialty  
- Send appointment requests  
- Check-out to view total payment  
- View assigned doctor after admin approval  

---

## 🛠️ **Admin Class**
- View & update profile  
- Remove patients  
- Check appointment requests  
- Auto-assign patients to correct doctors  
- Manage all system data  

---

# 📂 **PowerPoint Presentation**
**[Project Presentation](<assets/OOP Project.pptx>)**

---

# 🎥 **Video Demo**
**[Watch Demo](<assets/Video Demo.mp4>)**

---

# 📂 **Project Directory**
**[Project Folder](<Project/>)**

**[Project Solution](<Project/OOP Project.sln>)**

**[Project Files](<Project/OOP Project/>)**

---

# ⚙️ **How to Run the Project**

1. Clone or download the repository  
2. Inside the repository, you will find a main **Project** folder.  
   - This folder contains the **.sln** file, ready to open directly with **Visual Studio**.
3. If you are using another IDE (VS Code, CodeBlocks, etc.),  
   - Open the **inner project folder** located inside the main Project folder.  
   - It contains all the **header (.h)** and **source (.cpp)** files fully organized.  
   - Run the program through **source.cpp**.

4. Compile and run the project  
5. On launch:  
   - **New users → Register**  
   - **Existing users → Login**  
6. System will automatically load the correct interface:  
   - Doctor menu  
   - Patient dashboard  
   - Admin panel  
7. All changes save directly into the data files on exit.

---

# 👤 **Author Information**

**Name:** Omar Ashraf  
**College ID:** 202400725  
**College:** Zewail City University  
**Course:** CSAI 151 (Object-Oriented Programming)  

### 📫 Contact
**Personal Email:** omar.ashraf.hamed2017@gmail.com  
**College Email:** s-omar.amahmoud@zewailcity.edu.eg  
**LinkedIn:** https://www.linkedin.com/in/omar-ashraf-296ba1328/  

---

# 📜 **License**

This project is licensed under the **MIT License**.  
Feel free to use or extend it with proper credit.

<div align="center">
<sub>Built with 💻 and ☕ by Omar Ashraf. © 2025</sub>
</div>