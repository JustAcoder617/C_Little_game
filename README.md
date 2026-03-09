# 🎮 Whispers of Condemnation – O Motor por trás da Diversão! 🚀

[![License MIT / GPLv2](https://img.shields.io/badge/License-MIT%20%2F%20GPLv2-blue)](LICENSE)
[![GitHub stars](https://img.shields.io/github/stars/JustAcoder617/Whispers-of-Condemnation)](https://github.com/JustAcoder617/Whispers-of-Condemnation/stargazers)
[![GitHub issues](https://img.shields.io/github/issues/JustAcoder617/Whispers-of-Condemnation)](https://github.com/JustAcoder617/Whispers-of-Condemnation/issues)
[![GitHub forks](https://img.shields.io/github/forks/JustAcoder617/Whispers-of-Condemnation)](https://github.com/JustAcoder617/Whispers-of-Condemnation/network/members)

---

![Gameplay GIF](https://media.giphy.com/media/l0HlOvJ7yaacpuSas/giphy.gif)

Esqueça bibliotecas genéricas. Aqui está sendo construído o **coração de um game completo**, focado em **performance e automação de ponta**!  

---

## 🕹️ O Jogo em Primeiro Lugar

Este repositório sustenta a lógica de um **jogo real**. Toda a matemática e processamento são otimizados para que a experiência seja **fluida**.  

> **Nota:** A GUI ainda não é o foco – a prioridade é garantir um núcleo sólido e eficiente em ambiente CLI antes de receber camadas estéticas.

---

## 🌐 Automação via Webhooks e `cweb.h`

O `cweb.h` é o **sistema nervoso do motor**, garantindo comunicação inteligente e segurança de dados. Um dos pilares é a proteção de informações sensíveis:

```c
static inline char* descriptografar(char *dados, int tamanho, int chave)