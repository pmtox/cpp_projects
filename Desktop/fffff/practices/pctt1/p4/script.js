function generatePassword() {
        const upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const lower = "abcdefghijklmnopqrstuvwxyz";
        const number = "0123456789";
        const symbol = "!@#$%^&*()_+{}[]<>?,.";

        let finalChars = "";

        if (document.getElementById("upper").checked) finalChars += upper;
        if (document.getElementById("lower").checked) finalChars += lower;
        if (document.getElementById("number").checked) finalChars += number;
        if (document.getElementById("symbol").checked) finalChars += symbol;

        if (finalChars === "") {
            document.getElementById("result").innerText = "Select at least one option!";
            return;
        }

        const length = document.getElementById("length").value;
        let password = "";

        for (let i = 0; i < length; i++) {
            password += finalChars[Math.floor(Math.random() * finalChars.length)];
        }

        document.getElementById("result").innerText = password;
    }