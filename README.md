## Documentation Link 
[Merge Sort Link doc](https://docs.google.com/document/d/1MwsG6Z-qI7sCVjMgkKdY2g4z2U-QG12zi73V_1J3d98/edit?usp=sharing)

## Input Data Files  
[Data Files](https://drive.google.com/drive/folders/19q8HqMcbWaLbsxZ4liuR5Xqkg2WR2cDx?usp=sharing)


## How to Set Up and Run

### 1. Clone or Download the Project

You can either:

- **Clone the repository**:
  ```bash
  git clone https://github.com/paulavaduva/MergeSortParallel2.git
  ```

- **Download the ZIP** from GitHub and extract it locally.

---

### 2. Build the Project

- Open the `.sln` file in **Visual Studio 2022**.
- Set the build configuration to **x64** and **Debug**.
- Press `Ctrl+Shift+B` to build the project.

The compiled executable will be placed in:

```
project-folder\x64\Debug\
```

---

### 3. Prepare `run_all.bat`

- Move the `run_all.bat` file from the root folder into the `x64\Debug` directory (next to the compiled `.exe`).

---

### 4. Download the Input Data Files

- Download the input data archive from the following link:  
   **[Download input data](https://drive.google.com/drive/folders/19q8HqMcbWaLbsxZ4liuR5Xqkg2WR2cDx?usp=sharing)** 

- Extract all files (`data1.txt`, `data2.txt`, ..., `data10.txt`) into:

```
project-folder\x64\Debug\
```

---

### 5. Run the Project

- Navigate to the `x64\Debug` folder.
- Double-click `run_all.bat` to start.

The script will:

- Run `MergeSortParallel2.exe` on each input file using `mpiexec`.
- Collect and append execution results to a file named `results.txt`.

---

##  Output

All execution times will be saved in:

```
x64\Debug\results.txt
```

---
