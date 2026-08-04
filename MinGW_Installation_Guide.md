# Steps to Install MinGW on Windows

## Step 1: Download MinGW Installer

Open your browser and search:

**MinGW SourceForge**

Or use the official MinGW SourceForge download page:

**Link** : https://sourceforge.net/projects/mingw/files/Installer/mingw-get-setup.exe/download

**Download MinGW Installer**

The file should be:

```text
mingw-get-setup.exe
```

---

## Step 2: Run the `.exe` File

After downloading, open:

```text
mingw-get-setup.exe
```

Click **Install**.

---

## Step 3: Select Installation Directory

Keep the default location:

```text
C:\MinGW
```

Click **Continue**.

The **MinGW Installation Manager** will open.

---

## Step 4: Select GCC Compiler

In **MinGW Installation Manager**:

1. Click **Basic Setup**.
2. Find **mingw32-gcc-g++**.
3. Right-click on it.
4. Select **Mark for Installation**.

Also select:

- `mingw32-base`
- `mingw32-gcc-g++`

---

## Step 5: Apply Changes

Click:

**Installation → Apply Changes**

Then click **Apply**.

Wait for the installation to finish.

---

## Step 6: Add MinGW to PATH

After installation, go to:

**Windows Search → Environment Variables**

Open:

**Edit the system environment variables → Environment Variables**

Under **System variables**, 

select:
**Path**

Click:

**Edit → New**

Add:

```text
C:\MinGW\bin
```

Click **OK** on all windows.

---

## Step 7: Verify Installation

Open a **new CMD window**.

Type:

```bash
gcc --version
```

Then:

```bash
g++ --version
```

If you see the GCC version, MinGW has been successfully installed. ✅
