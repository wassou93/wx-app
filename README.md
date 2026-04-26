# wxApp (wxWidgets C++ Project)

A minimal wxWidgets GUI application using CMake on Linux (Arch-based setup) with proper editor support (Helix/clangd).

---

## 📦 Requirements

Install dependencies (Arch Linux):

```bash
paru -S wxwidgets-gtk3 cmake gcc
```

---

## ⚙️ Configure (Recommended Way)

This generates a proper build directory and `compile_commands.json` for clangd:

```bash id="gtk"
cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```

If you want to build with QT backend instead:

```bash id="qt5"
cmake -S . -B build   -DCMAKE_EXPORT_COMPILE_COMMANDS=ON   -DwxWidgets_CONFIG_EXECUTABLE=/usr/bin/wx-config-qt
```

---

## 🛠️ Build

```bash
cmake --build build
```

---

## 🚀 Run

```bash
./build/app
```

---

## 🧠 Editor Support (Helix / clangd)

This project generates:

```
build/compile_commands.json
```

To ensure clangd finds it, you can either:

### Option 1 (recommended)
Configure clangd to use `build/`

### Option 2 (symlink)

```bash
ln -sf build/compile_commands.json .
```

---

## 🧹 Clean build

```bash
rm -rf build
```

Then reconfigure:

```bash
cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
```

---

## 🧪 Minimal manual build (not recommended)

```bash
g++ src/main.cpp $(wx-config --cxxflags --libs) -o app
```

---

## 📁 Project structure

```
wx-app/
├── src/
│   └── main.cpp
├── build/
├── CMakeLists.txt
└── README.md
```

---

## 🪟 Example app

```cpp
#include <wx/wx.h>

class MyApp : public wxApp {
public:
    bool OnInit() override;
};

class MyFrame : public wxFrame {
public:
    MyFrame() : wxFrame(nullptr, wxID_ANY, "Hello wxWidgets") {}
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}
```

---

## ✅ Notes

- Always prefer CMake over manual compilation
- `compile_commands.json` is REQUIRED for good IDE/LSP support
- wxWidgets uses GTK3 backend on Arch (`wxwidgets-gtk3`)
