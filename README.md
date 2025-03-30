# 📦 OnTheWay - LMC Campus Delivery Route Planner

**OnTheWay** is a C++ application designed to assist with **package delivery planning** at Los Medanos College. It allows users to manage packages and automatically calculates the **optimal delivery route** across campus buildings using a graph-based system.

This project simulates real-world delivery logic and was created as a practical tool and learning experience in **data structures and algorithms**.

---

## 🚀 Features

- Add, view, and remove packages
- Each package includes:
  - Carrier name
  - Receiver name
  - Destination building
  - Weight and quantity
- Predefined campus graph with 23 buildings
- Dynamic graph with adjacency matrix representation
- Uses **Breadth-First Search (BFS)** to determine delivery route
- Text-based menu system for interaction

---

## 🛠️ Tech Stack

- **Language**: C++  
- **Concepts Used**:  
  - Classes and OOP  
  - Graphs (nodes & edges)  
  - BFS traversal  
  - Lists, vectors, strings, and file management  
  - Operator overloading

---

## 🧪 How It Works

1. The app builds a graph of LMC's campus buildings as nodes.
2. Users can add packages with delivery details.
3. The program calculates the shortest logical route from the **Receiving** area to all package destinations using **BFS**.
4. A clean route is displayed for the delivery driver.

---

## 🏫 Campus Buildings Modeled

Some of the 23 predefined buildings include:
- Receiving
- Library
- Core Floors
- Music Building
- ETEC/PTEC
- Student Union
- Science & Math Building
- Nursing Department
- Veterans Resource Center  
...and more.

---

## 🧑‍💻 Usage

To run the program:

1. Compile all files using a C++ compiler (e.g. `g++`):
   ```bash
   g++ main.cpp Util.cpp Graph.cpp Package.cpp -o OnTheWay
   ./OnTheWay
