# 📦 Sistema de Control d'Estoc en C

<p align="center">
  <img src="https://img.shields.io/badge/Llenguatge-C-blue.svg" alt="C">
  <img src="https://img.shields.io/badge/Estat-Funcional-brightgreen.svg" alt="Status">
  <img src="https://img.shields.io/badge/Plataforma-Linux%20%7C%20Windows-lightgrey.svg" alt="Platform">
</p>

---

## 📝 Descripció
Aquest programa és una eina de gestió d'inventari desenvolupada en **Llenguatge C**. Permet administrar un magatzem de fins a 10 productes mitjançant una interfície de consola intuïtiva, utilitzant estructures de dades (`struct`) i punters per a una gestió eficient de la memòria.

---

## ✨ Característiques Principals

<table style="width: 100%; border-collapse: collapse;">
  <tr style="background-color: #24292e; color: white;">
    <th style="padding: 10px; border: 1px solid #ddd;">Funció</th>
    <th style="padding: 10px; border: 1px solid #ddd;">Descripció</th>
  </tr>
  <tr>
    <td style="padding: 10px; border: 1px solid #ddd;"><b>➕ Alta de Productes</b></td>
    <td style="padding: 10px; border: 1px solid #ddd;">Afegeix nous articles amb ID autoincremental.</td>
  </tr>
  <tr>
    <td style="padding: 10px; border: 1px solid #ddd;"><b>📊 Visualització</b></td>
    <td style="padding: 10px; border: 1px solid #ddd;">Llistat complet de productes amb els seus detalls (ID, Nom, Estoc, Preu).</td>
  </tr>
  <tr>
    <td style="padding: 10px; border: 1px solid #ddd;"><b>💰 Gestió de Vendes</b></td>
    <td style="padding: 10px; border: 1px solid #ddd;">Redueix l'estoc de forma segura (control d'existències insuficients).</td>
  </tr>
  <tr>
    <td style="padding: 10px; border: 1px solid #ddd;"><b>📈 Reposició</b></td>
    <td style="padding: 10px; border: 1px solid #ddd;">Augmenta l'inventari de productes existents mitjançant l'ID.</td>
  </tr>
  <tr>
    <td style="padding: 10px; border: 1px solid #ddd;"><b>🔍 Cerca i Informes</b></td>
    <td style="padding: 10px; border: 1px solid #ddd;">Càlcul del valor total del magatzem.</td>
  </tr>
</table>

---

## 🛠️ Estructura del Codi
El codi està organitzat de forma modular utilitzant funcions específiques per a cada tasca:

* `main()`: Punt d'entrada que gestiona el menú interactiu i el flux principal del programa.

* `afegirProducte()`: Gestiona l'entrada de dades, l'assignació d'ID autoincremental i el control de límits del magatzem.

* `mostrarProductes()`: Recorre l'inventari i mostra un llistat detallat de tots els productes registrats.

* `cercarProducte()`: Utilitza cerca lineal per trobar i retornar un punter a un producte mitjançant el seu identificador.

* `vendreProducte()`: Gestiona la sortida de material verificant que hi hagi prou existències abans de la transacció.

* `reposarProducte()`: Permet incrementar la quantitat en estoc d'un producte existent al magatzem.

* `calcularValorTotal()`: Realitza la suma ponderada del valor econòmic de tot l'inventari (Total=∑quantitat×preu).

* `producteAmbMenysEstoc()`: Algorisme de comparació que cerca i retorna el producte amb el nivell d'existències més baix.

* `producteAmbMenysEstocFinal()`: Funció d'interfície que imprimeix el resultat de la cerca del producte amb menys estoc.

---

## 🚀 Instal·lació i Execució

Per compilar i executar aquest programa al teu servidor o local, segueix aquests passos:

1. **Compilar el codi:**
   ```bash
   gcc controlestoc.c -o control_estoc

   ./control_estoc
