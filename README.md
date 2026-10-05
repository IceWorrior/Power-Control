# PowerCtrl

A lightweight, customizable **power control GUI for Linux**, built with **C, GTK4, and CSS**.

PowerCtrl is designed as a simple alternative to tools like `wlogout`, with a focus on low resource usage, a clean interface, and easy customization.

## ✨ Features

- Lightweight native Linux application
- Built with C and GTK4
- Customizable appearance using GTK CSS
- SVG icon support
- Horizontal button layout
- Designed for Hyprland
- Power control actions such as:

  - Shutdown
  - Reboot
  - Logout
  - Sleep _(planned)_

## 🛠️ Technologies

- **C**
- **GTK4**
- **GLib**
- **GTK CSS**
- **SVG**
- **Hyprland**

## 📁 Project Structure

```text
PowerCtrl/
├── main.c
├── style.css
├── icons/
│   ├── power.svg
│   ├── reboot.svg
│   ├── logout.svg
│   └── sleep.svg
└── README.md
```

## 📦 Requirements

Arch Linux:

```bash
sudo pacman -S gtk4 base-devel pkgconf
```

A Linux desktop environment with GTK4 is required.

## 🔨 Build

Clone the repository:

```bash
git clone https://github.com/YOUR_USERNAME/PowerCtrl.git
cd PowerCtrl
```

Compile the application:

```bash
gcc main.c -o powerctrl $(pkg-config --cflags --libs gtk4)
```

## ▶️ Run

```bash
./powerctrl
```

## 🎨 Customization

The interface can be customized through `style.css`.

For example:

```css
window {
  background: #11111b;
}

button {
  background: #1e1e2e;
  color: #cdd6f4;
  border-radius: 15px;
  padding: 20px;
}

button:hover {
  background: #313244;
}
```

You can also replace the SVG files inside the `icons/` directory with your own icons.

## 🖥️ Hyprland

PowerCtrl can be configured as a floating and centered window in Hyprland.

Add an appropriate window rule to your Hyprland configuration:

```ini
windowrule {
    match:class = ^(com\.saksham\.powerctrl)$
    float = on
    center = on
}
```

Check the application's class with:

```bash
hyprctl clients
```

## 🚧 Roadmap

Planned improvements:

- [ ] Confirmation screen before shutdown/reboot
- [ ] Sleep action
- [ ] Keyboard navigation
- [ ] Better animations
- [ ] Improved SVG icon handling
- [ ] Transparent/blurred background
- [ ] Hyprland-specific launcher behavior
- [ ] Installation script
- [ ] Arch package

## 🤝 Contributing

Contributions, suggestions, and improvements are welcome.

1. Fork the repository
2. Create a branch
3. Make your changes
4. Commit your changes
5. Open a pull request

## 📄 License

This project is open source. A license can be added to the repository depending on how you want to distribute PowerCtrl.
