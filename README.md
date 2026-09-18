# Gurgel — Sprint 3

## Prototipagem Funcional e Integração

O Gurgel é uma solução para gerenciamento inteligente de carregamento de veículos elétricos.

Nesta Sprint 3, o objetivo foi transformar a proposta em um protótipo funcional, demonstrando a integração entre sensores, gerenciamento de potência, dados de carregamento, Python e a plataforma Gurgel.

---

## Objetivo

Demonstrar uma solução capaz de:

- coletar dados de energia e demanda;
- acompanhar o carregamento;
- controlar a potência disponível;
- priorizar energia solar quando possível;
- registrar sessões de carregamento;
- calcular consumo e custo;
- apresentar os dados em gráficos;
- conectar essas informações à plataforma Gurgel e ao GurAI.

---

## Arquitetura

O funcionamento principal pode ser representado pelo seguinte fluxo:

**Sensores → Gerenciamento de potência → Registro → Python → Dashboard → Gurgel/GurAI**

O protótipo utiliza o Tinkercad para representar a camada de sensores e controle de forma simulada.

---

## Protótipo

No Tinkercad foram utilizados:

- Arduino Uno R3;
- 2 potenciômetros;
- botão;
- LEDs;
- resistores de 220 Ω.

### Sensores

O primeiro potenciômetro representa a energia solar disponível.

O segundo representa a demanda de carregamento.

Os potenciômetros são utilizados como uma forma de simular valores variáveis dos sensores.

### Estados do sistema

Os LEDs representam diferentes situações:

- verde: carregamento normal;
- amarelo: potência reduzida;
- vermelho: demanda acima do limite;
- azul: energia solar priorizada.

O limite utilizado na simulação é de 10 kW.

---

## Gerenciamento de potência

O sistema verifica os valores de demanda e energia solar.

A lógica utilizada é:

1. Quando a demanda ultrapassa 10 kW, a potência é limitada.
2. Quando existe energia solar suficiente, ela é priorizada.
3. Quando a demanda está elevada, o sistema indica potência reduzida.
4. Nos demais casos, o carregamento funciona normalmente.

A ideia é evitar sobrecarga e utilizar melhor a energia disponível.

---

## Python

O Python é utilizado para organizar, processar e visualizar os dados das sessões.

Foram utilizadas as bibliotecas:

- pandas;
- numpy;
- matplotlib;
- seaborn.

Os dados das sessões estão no arquivo `dados.csv`.

---

## Dashboard

O dashboard apresenta:

- quantidade de sessões;
- energia total;
- energia solar;
- energia da rede;
- custo total;
- potência média;
- maior potência;
- menor potência;
- energia consumida por sessão;
- custo por sessão;
- potência por sessão;
- distribuição entre energia solar e energia da rede.

---

## Resultados

Com os dados utilizados na simulação, foram obtidos:

- **8 sessões**
- **76,75 kWh** de energia total
- **39,90 kWh** de energia solar
- **36,85 kWh** de energia da rede
- **R$ 88,86** de custo acumulado
- **6,73 kW** de potência média

Os valores utilizados são simulados e foram utilizados para demonstrar o funcionamento do sistema.

---

## Plataforma Gurgel

A plataforma desenvolvida pelo grupo possui telas para:

- monitoramento dos carregadores;
- visualização de estações no mapa;
- consulta de carregadores;
- reserva de carregadores;
- confirmação de reservas;
- faturas;
- pagamento;
- reservas de restaurantes;
- interação com o GurAI.

---

## GurAI

O GurAI funciona como uma camada de interação com o usuário.

A proposta é utilizar os dados e funções disponíveis no sistema para auxiliar o usuário em ações como:

- encontrar carregadores;
- consultar informações;
- realizar reservas;
- consultar informações sobre carregamento;
- conectar a experiência de carregamento com estabelecimentos.

Também foi desenvolvida uma proposta de sugestão baseada no cotidiano do usuário.

---

## Sustentabilidade

O Gurgel busca contribuir para uma utilização mais eficiente da infraestrutura de carregamento por meio de:

- gerenciamento da demanda;
- utilização da energia solar disponível;
- acompanhamento do consumo;
- análise de custos;
- melhor distribuição da potência.

---

## Estrutura do projeto

```text
sprint_03_gurgel/
│
├── README.md
│
├── python/
│   ├── dashboard.py
│   ├── gerenciamento.py
│   ├── dados.csv
│   └── requirements.txt
│
├── tinkercad/
│   ├── teste_potenciometros.ino
│   └── prototipo_gurgel.ino
│
├── docs/
│   ├── diagrama_integracao.png
│   └── dashboard.png
│
└── imagens/
    └── telas/
