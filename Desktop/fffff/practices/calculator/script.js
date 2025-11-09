const buttonLayout = [
    '7', '8', '9', '/',
    '4', '5', '6', '*',
    '1', '2', '3', '-',
    '0', '.', '=', '+'
];

const buttonsContainer = document.getElementById('buttons');
const display = document.getElementById('display');

// 🧠 Use for loop to create buttons dynamically
for (let i = 0; i < buttonLayout.length; i++) {
    const btn = document.createElement('button');
    btn.textContent = buttonLayout[i];
    btn.addEventListener('click', () => handleClick(buttonLayout[i]));
    buttonsContainer.appendChild(btn);
}

function handleClick(value) {
    if (value === '=') {
        try {
            display.value = eval(display.value); // evaluate the math
        } catch {
            display.value = 'Error';
        }
    } else {
        display.value += value;
    }
}
