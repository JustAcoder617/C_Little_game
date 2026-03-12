const repoBtn = document.getElementById("repo");
const personBtn = document.getElementById("person");

// Função genérica para abrir links em nova aba
const openLink = (url) => {
    window.open(url, '_blank');
};

// Eventos
repoBtn.addEventListener("click", () => {
    openLink('https://github.com/JustAcoder617/Whispers-of-Condemnation/blob/main/modularization/cweb.h');
});

personBtn.addEventListener("click", () => {
    openLink('https://github.com/JustAcoder617');
});