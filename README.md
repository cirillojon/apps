# Simple C++ Application 

This is a work in progress app that I am building to learn more about C++

## Main Form

The `MainForm` is the primary window of the application, and it contains two buttons:
- **Calculator**: Opens the `CalculatorForm` when clicked.
- **App2**: Placeholder button for adding functionality related to a second application (currently not implemented).

Here's a brief overview of the `MainForm` class:

1. The constructor initializes the UI components (buttons) and adds them to the form.
2. Event handlers are set up for button clicks.
3. The `CalculatorButton_Click` method creates an instance of `CalculatorForm` and opens it using `ShowDialog()`.

## Calculator Form

The `CalculatorForm` is a simple calculator application that allows the user to add two numbers.

The form contains the following UI components:
- Two textboxes for entering numbers.
- A "+" button to trigger the addition.
- A label to display the result.

Here's a brief overview of the `CalculatorForm` class:

1. The constructor calls the `InitializeComponent()` method to set up the UI components.
2. The `InitializeComponent()` method creates and configures the textboxes, button, and label.
3. The `AddButton_Click` event handler is added to the "+" button, which performs the addition and updates the result label.
