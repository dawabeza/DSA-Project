# 🛒 Supermarket Management System (DSA Project)

A robust, modular Supermarket Management System developed in C++. This project is designed to demonstrate core **Data Structures and Algorithms (DSA)** principles by managing inventory, customers, suppliers, and sales without relying on built-in STL containers like `std::vector`.

---

## 🏗️ System Architecture

The project follows a **Modular Design**, separating the data storage, business logic, and algorithms into distinct layers.

### 📁 Directory Structure

* **`ds/`**: Low-level custom data structures (The foundation).
* **`algorithm/`**: Optimized sorting and searching logic.
* **`include/`**: Header files defining the system models and managers.
* **`src/`**: Implementation of the business logic.
* **`data/`**: Persistent storage using `.txt` files.
* **`build/`**: Compiled binary files.

---

## 🧠 Data Structures & Algorithms (The "DSA" Core)

### 1. Custom Dynamic Array (`DynamicArray<T>`)

Used for storing **Products, Customers, and Suppliers**.

* **Feature**: Implements manual memory management and array resizing.
* **Complexity**:  for random access; Amortized  for insertion.

### 2. Custom Linked List (`LinkedList<T>`)

Used for the **Shopping Cart**.

* **Feature**: Dynamic node allocation for items during a transaction.
* **Complexity**:  for adding/removing items from the cart.

### 3. Merge Sort Algorithm ()

Used for **Stock Reporting**.

* **Logic**: A recursive "Divide and Conquer" approach implemented in the `algorithm/` folder. It sorts products by quantity to identify low-stock items efficiently.

### 4. Linear Search ()

Used for **ID Verification**.

* **Logic**: Scans the DynamicArray to ensure unique IDs and to find products during checkout.

---

## 🛠️ Features

* **Inventory Control**: Add, Update, and Delete products with unique ID enforcement.
* **Stock Management**: Restock shipments and automated low-stock alerts.
* **Point of Sale (POS)**: Process sales using a Linked List cart and update customer loyalty points.
* **Persistence**: Data is serialized to `.txt` files on exit and de-serialized on startup.
* **Financial Reports**: Calculate total revenue and transaction history from sales logs.

---

## 💻 How to Build and Run

### Manual Compilation (Recommended)

Since the project uses a custom build structure, create a `build` folder first:

```bash
mkdir build

```

Then compile using the following command:

```bash
g++ -std=c++17 -Iinclude -Ialgorithm -Ids src/*.cpp -o build/supermarket

```

### Running the Application

```bash
./build/supermarket

```

---

## 📜 Project Ethics & Integrity

* **Data Integrity**: Unique ID checks prevent data corruption.
* **Memory Management**: Proper use of destructors and pointers to prevent memory leaks.
* **Scalability**: The use of Merge Sort and Dynamic Arrays ensures the system remains fast as data grows.

---
