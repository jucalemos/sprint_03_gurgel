# Resultados, metodologia e limitações — Gurgel Sprint 4

## 1. Origem dos dados

O arquivo analisado é `python/dados.csv`, com oito registros. Os valores estão registrados com separador de campos ponto e vírgula e vírgula decimal. Os resultados abaixo são agregações calculadas a partir desses registros.

**Classificação:** dados ilustrativos/simulados. Eles não são medições certificadas de energia, leituras de inversor GoodWe ou cobranças reais.

## 2. Indicadores do CSV atual

| Indicador | Resultado |
|---|---:|
| Sessões registradas | 8 |
| Energia total registrada | 75,75 kWh |
| Energia solar registrada | 39,90 kWh |
| Energia da rede registrada | 35,85 kWh |
| Soma dos custos informados | R$ 88,86 |
| Potência média das sessões | 6,725 kW |
| Maior potência no conjunto | 9,0 kW |
| Menor potência no conjunto | 4,5 kW |

A energia solar corresponde a aproximadamente 52,7% do total informado no CSV; a parcela da rede corresponde a aproximadamente 47,3%. Esses percentuais descrevem apenas a distribuição dos dados ilustrativos e não comprovam economia real ou redução de carbono.

## 3. Como reproduzir

No terminal, entre na pasta `python/` e execute:

```bash
python -m pip install pandas numpy matplotlib seaborn
python simulacao.py
python dashboard.py
```

Para executar a regra de gerenciamento com valores digitados:

```bash
python gerenciamento.py
```

Execute os comandos a partir da pasta `python/`, pois os scripts leem `dados.csv` por caminho relativo.

## 4. O que os resultados demonstram

- Os scripts conseguem resumir um conjunto de sessões.
- O conjunto de dados permite comparar energia, custos e potência entre sessões.
- O código de gerenciamento representa a limitação da potência acima de 10 kW.
- O modelo separa, por regra, uma parcela de energia solar simulada e uma parcela atribuída à rede.

## 5. O que os resultados não demonstram

- Não comprovam redução de emissões de carbono.
- Não comprovam redução real de custos em comparação com uma linha de base.
- Não são medições obtidas de um veículo ou carregador real.
- Não demonstram comunicação direta com inversor, bateria ou carregador GoodWe.
- Não comprovam operação segura de um carregador comercial.

## 6. Limitações técnicas

1. Os potenciômetros simulam os valores de solar e demanda.
2. O CSV é um conjunto ilustrativo.
3. A placa e os scripts Python não estão conectados em tempo real nos arquivos documentados.
4. A tarifa no código Arduino é fixa em R$ 1,20/kWh; o CSV utiliza tarifas variadas por sessão.
5. A energia solar e da rede no CSV devem ser entendidas como entradas simuladas, e não dados de medidor.
6. A lógica de estado dos LEDs é uma demonstração simplificada e não substitui proteções elétricas certificadas.

## 7. Melhorias futuras

- Padronizar a origem dos dados e a forma de cálculo da energia.
- Adicionar testes automatizados para o limite de potência.
- Criar comunicação documentada entre hardware e aplicação, se necessário.
- Registrar unidades, tarifas e timestamps de forma consistente.
- Integrar equipamentos reais somente após validação técnica e de segurança.
- Medir indicadores ambientais com método e fatores de emissão explicitamente referenciados.
