document.getElementById("sendBtn").addEventListener("click", () => {
  const input = document.getElementById("userInput");
  const msg = input.value.trim();
  if (!msg) return;

  const chatBox = document.getElementById("chat-box");
  const userMsg = document.createElement("p");
  userMsg.innerHTML = `<strong>You:</strong> ${msg}`;
  chatBox.appendChild(userMsg);

  input.value = "";
  chatBox.scrollTop = chatBox.scrollHeight;
});
