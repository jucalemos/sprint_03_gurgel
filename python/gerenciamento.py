limite_potencia = 10.0


def gerenciar_potencia(demanda, potencia_solar):

    if demanda > limite_potencia:
        potencia_liberada = limite_potencia
        status = "Sobrecarga - potencia limitada"

    elif potencia_solar >= demanda and demanda > 0:
        potencia_liberada = demanda
        status = "Energia solar priorizada"

    elif demanda >= 8:
        potencia_liberada = demanda
        status = "Potencia reduzida"

    else:
        potencia_liberada = demanda
        status = "Carregamento normal"

    potencia_solar_usada = min(potencia_solar, potencia_liberada)
    potencia_rede = potencia_liberada - potencia_solar_usada

    return potencia_liberada, potencia_solar_usada, potencia_rede, status


print("================================")
print("       GURGEL")
print(" GERENCIAMENTO DE POTENCIA")
print("================================")

demanda = float(input("Digite a demanda em kW: "))
potencia_solar = float(input("Digite a potencia solar em kW: "))

potencia_liberada, solar_usada, rede_usada, status = gerenciar_potencia(
    demanda,
    potencia_solar
)

print()
print("Potencia liberada:", round(potencia_liberada, 2), "kW")
print("Solar utilizada:", round(solar_usada, 2), "kW")
print("Rede utilizada:", round(rede_usada, 2), "kW")
print("Status:", status)
