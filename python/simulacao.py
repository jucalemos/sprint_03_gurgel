import pandas as pd

dados = pd.read_csv("dados.csv", sep=";", decimal=",")

energia_total = dados["Energia_kWh"].sum()
solar_total = dados["Solar_kWh"].sum()
rede_total = dados["Rede_kWh"].sum()
custo_total = dados["Custo_R$"].sum()

media_potencia = dados["Potencia_kW"].mean()
total_sessoes = len(dados)

print("================================")
print("       GURGEL")
print(" CHARGEGRID INTELLIGENCE")
print("================================")

print()

print("Total de sessoes:", total_sessoes)

print("Energia consumida:",
      round(energia_total, 2), "kWh")

print("Energia solar:",
      round(solar_total, 2), "kWh")

print("Energia da rede:",
      round(rede_total, 2), "kWh")

print("Custo total: R$",
      round(custo_total, 2))

print("Potencia media:",
      round(media_potencia, 2), "kW")

print()

print("Historico das sessoes:")
print(dados[[
    "Sessao",
    "Potencia_kW",
    "Energia_kWh",
    "Custo_R$"
]])
