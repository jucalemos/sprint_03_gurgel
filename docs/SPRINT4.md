# Gurgel — Sprint 4
## Solução final integrada e inovadora GoodWe

> **Escopo e transparência:** este documento descreve o protótipo acadêmico disponível no repositório. A montagem do Tinkercad utiliza Arduino Uno R3, dois potenciômetros, botão, LEDs e resistores. Os potenciômetros representam valores simulados de potência solar e demanda; portanto, os resultados não são medições de uma instalação elétrica real. A documentação não afirma integração física direta com equipamentos GoodWe.

## 1. Visão geral

O Gurgel é uma proposta de gerenciamento inteligente da recarga de veículos elétricos. O projeto conecta uma simulação embarcada de gerenciamento de potência, scripts Python para análise de sessões e uma proposta de plataforma digital com monitoramento e o assistente GurAI.

A solução busca responder a quatro questões: como acompanhar a recarga, como respeitar um limite de potência, como estimar o uso de energia solar versus rede e como apresentar consumo e custos ao usuário.

## 2. Arquitetura implementada e demonstrada

```text
[Tinkercad: Arduino Uno + potenciômetros + botão + LEDs]
                   |
                   | leitura analógica e regras de controle
                   v
       [Estados visuais + Serial Monitor]
                   |
                   | análise de conjunto de dados separado
                   v
        [Python: pandas / NumPy]
                   |
                   v
      [Resumo e gráficos: Matplotlib / Seaborn]

[Plataforma Gurgel / GurAI]
  interface demonstrativa documentada no README da Sprint 3
```

O protótipo de hardware simulado e os scripts de análise por CSV são componentes relacionados pelo conceito, mas os arquivos atuais não demonstram uma conexão automática em tempo real entre o Arduino e o dashboard Python. O CSV é analisado separadamente.

## 3. Protótipo de controle

Arquivo: `tinkercad/prototipo.ino`

Componentes documentados:
- Arduino Uno R3;
- dois potenciômetros ligados às entradas analógicas A0 e A1;
- botão de controle ligado ao pino digital 7;
- LEDs verde, amarelo, vermelho e azul nos pinos digitais 8 a 11;
- resistores para limitar corrente dos LEDs.

Os potenciômetros representam:
- A0: potência solar simulada, escalada para 0–12 kW;
- A1: demanda de recarga simulada, escalada para 0–15 kW.

O programa utiliza um limite de potência de 10 kW e uma tarifa fixa de R$ 1,20/kWh. O botão alterna o estado da sessão. Durante uma sessão, o programa calcula potência liberada, parcela solar, parcela da rede, energia acumulada e custo estimado, enviando os valores ao Serial Monitor.

### Estados dos LEDs

| LED | Condição representada no código |
|---|---|
| Vermelho | Demanda acima de 10 kW; potência liberada limitada a 10 kW |
| Azul | Potência solar simulada suficiente para cobrir a demanda |
| Amarelo | Demanda igual ou superior a 8 kW, sem condição solar prioritária |
| Verde | Funcionamento normal nos demais casos |

O desenho do circuito enviado pela equipe mostra Arduino Uno, dois potenciômetros, botão e quatro LEDs com resistores. Para a documentação final, manter a imagem real do Tinkercad no diretório `imagens/` e referenciá-la no README.

## 4. Lógica de gerenciamento

Arquivo: `python/gerenciamento.py`

A função `gerenciar_potencia(demanda, potencia_solar)` aplica um limite de 10 kW. Em seguida, estima quanto da potência liberada pode ser suprida pela energia solar simulada e quanto viria da rede:

- potência liberada = menor valor entre demanda e limite;
- potência solar utilizada = menor valor entre potência solar e potência liberada;
- potência da rede = potência liberada menos potência solar utilizada.

O script Python solicita os valores pelo terminal e apresenta potência liberada, parcela solar, parcela da rede e status.

## 5. Análise de dados e dashboard

Arquivos:
- `python/dados.csv`
- `python/simulacao.py`
- `python/dashboard.py`

O CSV contém oito sessões ilustrativas. Os scripts utilizam pandas para ler os dados; o dashboard também utiliza NumPy para agregações, Matplotlib para gráficos e Seaborn para gráficos estatísticos.

O dashboard apresenta resumo, histórico e quatro visualizações: energia por sessão, custo por sessão, potência por sessão com linha de referência de 10 kW e distribuição de energia solar versus rede.

### Resultados calculados a partir do CSV

Valores calculados a partir dos oito registros atuais do arquivo `python/dados.csv`:

| Indicador | Resultado |
|---|---:|
| Sessões | 8 |
| Energia total | 75,75 kWh |
| Energia solar registrada | 39,90 kWh |
| Energia da rede registrada | 35,85 kWh |
| Soma do custo informado por sessão | R$ 88,86 |
| Potência média | 6,725 kW |
| Maior potência de sessão no CSV | 9,0 kW |
| Menor potência de sessão no CSV | 4,5 kW |

**Atenção à consistência dos dados:** os totais acima são calculados diretamente a partir das linhas do CSV atualmente versionado. Eles podem diferir de números descritos em versões anteriores da documentação. A energia solar e a energia da rede são valores simulados/ilustrativos, não medições físicas. O custo acumulado é a soma dos custos informados no CSV; não é uma medição de cobrança real.

## 6. Plataforma e GurAI

O README anterior descreve telas de monitoramento, mapa de estações, consulta e reserva de carregadores, faturas, pagamentos e interação com GurAI. As imagens existentes em `imagens/` podem documentar a interface.

A camada GurAI é apresentada como recurso de interação com o usuário. A documentação deve evitar afirmar que o assistente controla diretamente o hardware, executa pagamentos reais ou altera a potência física, a menos que essas integrações tenham sido efetivamente implementadas e testadas.

## 7. Relação com o desafio GoodWe

A proposta se relaciona ao desafio por trabalhar com gerenciamento da demanda, consideração da energia solar, estimativa da energia da rede e visualização de consumo e custo. Esses elementos se conectam conceitualmente a sistemas de gestão energética que integram geração, consumo e armazenamento.

No protótipo atual, a energia solar é representada por um potenciômetro e não há evidência nos arquivos descritos de comunicação direta com inversores, baterias ou carregadores GoodWe. Assim, a compatibilidade GoodWe deve ser apresentada como **alinhamento conceitual e possibilidade de integração futura**, não como integração física já concluída.

## 8. Sustentabilidade e avaliação crítica

Benefícios potenciais:
- tornar a demanda de recarga mais visível;
- demonstrar uma regra simples de limitação de potência;
- representar a priorização da energia solar disponível;
- estimar a divisão entre energia solar e energia da rede;
- facilitar a leitura de consumo e custo por meio de gráficos.

Limitações:
- valores de solar e demanda são simulados por potenciômetros;
- o CSV contém dados ilustrativos;
- não há, nos arquivos analisados, medição certificada de energia nem teste em carregador real;
- não há evidência de conexão automática entre a placa e os scripts Python;
- não foi calculada uma redução comprovada de emissões de carbono;
- não foi confirmada integração direta com equipamentos GoodWe.

Por essas razões, o projeto demonstra uma prova de conceito acadêmica, não um sistema pronto para comandar infraestrutura elétrica comercial.

## 9. Tecnologias

- Arduino Uno R3 e ambiente de simulação Tinkercad;
- C/C++ para Arduino (`.ino`);
- Python;
- pandas;
- NumPy;
- Matplotlib;
- Seaborn;
- CSV para dados de sessão;
- GitHub para versionamento e documentação.

## 10. Como executar os scripts Python

A partir da pasta `python/`, instalar as dependências usadas pelo dashboard:

```bash
python -m pip install pandas numpy matplotlib seaborn
```

Executar o resumo da simulação:

```bash
python simulacao.py
```

Executar o dashboard de gráficos:

```bash
python dashboard.py
```

Os scripts leem `dados.csv` por caminho relativo; execute-os a partir da pasta `python/` para que o arquivo seja encontrado.

Para testar a regra de potência interativamente:

```bash
python gerenciamento.py
```

## 11. Melhorias recomendadas

1. Unificar o nome dos arquivos e atualizar referências no README.
2. Documentar a ligação dos pinos com uma imagem do circuito.
3. Validar os totais do CSV e mantê-los consistentes em toda a documentação.
4. Separar claramente medições, dados simulados e metas futuras.
5. Caso o grupo avance para integração física, implementar e documentar um canal de comunicação entre o Arduino/ESP32 e a aplicação, com tratamento de erros.
6. Para alegar integração GoodWe, indicar o equipamento, protocolo, dados efetivamente lidos e evidências do teste.
7. Adicionar fontes oficiais consultadas para a documentação do Arduino, Python e equipamentos GoodWe usados como referência.

## 12. Referências

Incluam os links específicos consultados durante o trabalho:
- Arduino — documentação oficial: https://docs.arduino.cc/
- Python — documentação oficial: https://docs.python.org/3/
- pandas — documentação: https://pandas.pydata.org/docs/
- NumPy — documentação: https://numpy.org/doc/
- Matplotlib — documentação: https://matplotlib.org/stable/
- Seaborn — documentação: https://seaborn.pydata.org/
- GoodWe — portal oficial: https://www.goodwe.com/

As referências acima são portais de documentação; acrescentem páginas específicas dos modelos ou tecnologias GoodWe que o grupo realmente estudou.
