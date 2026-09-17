import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

dados = pd.read_csv("dados.csv", sep=";", decimal=",")

energia_total = np.sum(dados["Energia_kWh"])
solar_total = np.sum(dados["Solar_kWh"])
rede_total = np.sum(dados["Rede_kWh"])
custo_total = np.sum(dados["Custo_R$"])

media_potencia = np.mean(dados["Potencia_kW"])
maior_potencia = np.max(dados["Potencia_kW"])
menor_potencia = np.min(dados["Potencia_kW"])

total_sessoes = len(dados)

print("================================")
print("           GURGEL")
print("   CHARGEGRID INTELLIGENCE")
print("================================")

print()

print("Total de sessoes:", total_sessoes)
print("Energia total:", round(energia_total, 2), "kWh")
print("Energia solar:", round(solar_total, 2), "kWh")
print("Energia da rede:", round(rede_total, 2), "kWh")
print("Custo total: R$", round(custo_total, 2))
print("Potencia media:", round(media_potencia, 2), "kW")
print("Maior potencia:", round(maior_potencia, 2), "kW")
print("Menor potencia:", round(menor_potencia, 2), "kW")

print()
print("Historico das sessoes:")
print(dados[[
    "Sessao",
    "Potencia_kW",
    "Duracao_h",
    "Energia_kWh",
    "Custo_R$"
]])

sns.set_theme()

plt.figure(figsize=(8, 5))

sns.barplot(
    data=dados,
    x="Sessao",
    y="Energia_kWh"
)

plt.title("Energia consumida por sessao")
plt.xlabel("Sessao")
plt.ylabel("Energia (kWh)")

plt.show()


plt.figure(figsize=(8, 5))

sns.barplot(
    data=dados,
    x="Sessao",
    y="Custo_R$"
)

plt.title("Custo por sessao")
plt.xlabel("Sessao")
plt.ylabel("Custo (R$)")

plt.show()


energia = [solar_total, rede_total]
nomes = ["Energia Solar", "Energia da Rede"]

plt.figure(figsize=(6, 6))

plt.pie(
    energia,
    labels=nomes,
    autopct="%1.1f%%"
)

plt.title("Distribuicao da energia utilizada")

plt.show()
