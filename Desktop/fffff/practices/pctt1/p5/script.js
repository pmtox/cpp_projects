const stars = document.querySelectorAll(".star");
    const infoBox = document.getElementById("info");

    stars.forEach(star => {
        star.addEventListener("mousemove", (e) => {
            const name = star.getAttribute("data-name");
            const distance = star.getAttribute("data-distance");
            const fact = star.getAttribute("data-fact");

            infoBox.innerHTML = `
                <h3>${name}</h3>
                <p><strong>Distance:</strong> ${distance}</p>
                <p>${fact}</p>
            `;

            infoBox.style.left = e.pageX + 15 + "px";
            infoBox.style.top = e.pageY + 15 + "px";
            infoBox.style.opacity = 1;
        });

        star.addEventListener("mouseleave", () => {
            infoBox.style.opacity = 0;
        });
    });