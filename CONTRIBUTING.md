# Contributing to ESP32 Starter Template

First off, thank you for considering contributing to ESP32 Starter Template! It's people like you that make this template such a great resource for the community.

## Code of Conduct

This project and everyone participating in it is governed by our Code of Conduct. By participating, you are expected to uphold this code.

## How Can I Contribute?

### Reporting Bugs

Before creating bug reports, please check the existing issues as you might find out that you don't need to create one. When you are creating a bug report, please include as many details as possible:

* **Use a clear and descriptive title**
* **Describe the exact steps to reproduce the problem**
* **Provide specific examples to demonstrate the steps**
* **Describe the behavior you observed and what behavior you expected**
* **Include screenshots if possible**
* **Include your ESP32 board model and PlatformIO version**

### Suggesting Enhancements

Enhancement suggestions are tracked as GitHub issues. When creating an enhancement suggestion, please include:

* **Use a clear and descriptive title**
* **Provide a detailed description of the suggested enhancement**
* **Explain why this enhancement would be useful**
* **List some examples of how this enhancement would be used**

### Pull Requests

* Fill in the required template
* Follow the coding style (we use the Arduino coding style)
* Include comments in your code when necessary
* Test your changes with multiple ESP32 boards if possible
* Update the README.md if you're adding new features

## Development Setup

1. Fork the repository
2. Clone your fork:
   ```bash
   git clone https://github.com/your-username/esp32-starter-template.git
   ```
3. Create a branch:
   ```bash
   git checkout -b feature/your-feature-name
   ```
4. Make your changes and test thoroughly
5. Commit your changes:
   ```bash
   git commit -m "Add some feature"
   ```
6. Push to your fork:
   ```bash
   git push origin feature/your-feature-name
   ```
7. Open a Pull Request

## Coding Style

* Use Arduino coding style
* Use meaningful variable names
* Add comments for complex logic
* Keep functions small and focused
* Use `#define` for constants

## Testing

Before submitting a PR, please test:

* Build succeeds: `pio run`
* Upload works: `pio run --target upload`
* Serial monitor shows expected output: `pio device monitor`

## Community

* Join our discussions in the Issues section
* Help others who are new to ESP32 development
* Share your projects built with this template!

## License

By contributing, you agree that your contributions will be licensed under the MIT License.
