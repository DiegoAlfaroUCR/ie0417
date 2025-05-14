# Laboratorio 4 - Patrones de diseño en entrevistas técnicas

## Pregunta 1: Creación de mazo de cartas para Blackjack (21)

Esta pregunta tomada del libro Cracking the Code Interview (pregunta 7.1), indica lo siguiente:

> Diseñe las estructuras de datos que usaría para un mazo genérico de cartas. Explique como asignaría subclases de dichas estructuras para implementar el juego blackjack.

Se divide este concepto para manejar distintos problemas. Primero se debe asignar una estructura de datos que sea capaz de contener objetos de cartas individuales, con sus características como el Suit (símbolo de la carta, ej: Diamante), rank (rango o tipo de carta, ej: Rey) y su valor (valor numérico, ej: 10 para un rey en el caso del blackjack). Luego, es indispensable crear una estructura que contenga estas cartas de forma desordenada para jugar y que se use como mazo de la mesa. Finalmente, se deben asignar jugadores, incluyendo el dealer, los cuales puedan recibir cartas (si así lo desean) y ganar según las reglas. Se reconoce que la pregunta solo consulta sobre la forma en la que se definirían las estructuras, no la implementación de la lógica de juego ni interfaz.

### Solución y patrones propuestos

1. Cartas individuales:

   Debido a que cada carta debe contener varios atributos, se crea un objeto carta con las tres características (suit, rank, valor). Debido a que python no emplea structs comúnmente, se puede crear una clase `Carta` con atributos `suit`, `rank`, un inicializador que establezca dichos valores y getters para no acceder directamente a atributos de la clase. Para la generación del valor, se puede definir un método en la clase que lo genere según el rango de la carta. Una de las cartas, el As (Ace), posee la particularidad que se le puede asignar el valor 1 o 11, por lo que objetos cuyos atributo `rank` sea `A` deben permitir escoger el valor al usuario.

2. Jugadores:

   Cada jugador se construye según una clase que posea un identificador único (como un nombre) y la mano de cartas que posee el jugador en el momento. Debe tener un método para obtener el score (puntos) total de la mano que posee. Existe una variante especial del jugador, el dealer, por lo que se puede establecer una interfaz común entre ambas usando **Factory Method**. Este se usa para que la lógica de juego pueda funcionar para todos los objetos jugadores (como que pueda comparar el score de todos usando una misma interfaz), pero que se permitan funcionalidades distintas para el dealer.

3. Mazo/deck:

   El mazo de cartas que se tiene en la mesa debe ser único y accesible a todos los jugadores por medio de los métodos apropiados. Se plantea una clase que emplee **Singleton** para lograr estas características, asegurando que si los objetos jugadores intentan generar un nuevo objeto `Mazo` solo se genere uno nuevo si no existe. En caso de que sean jugadores nuevos uniéndose a la mesa, estos solicitarán cartas al mazo ya existente. Debido a la naturaleza del juego, el objeto Mazo debe proveer métodos que permitan sacar la carta más arriba del mazo, más no permitir acceso de lectura/escritura del mismo. Además debe poseer un método para generar/regenerar el mazo con la enteridad de las cartas de un mazo real, y con un orden aleatorio.

### Implementación en código

Código generado en conjunto con modelos de machine learning.

Para la clase `Carta`:

```python
class Card:
    def __init__(self, suit, rank):
        self.suit = suit      # 'Corazones', 'Diamantes', etc.
        self.rank = rank      # '2'-'10', 'J', 'Q', 'K', 'A'
        self.value = self._assign_value(rank)

    def _assign_value(self, rank):
        if rank in ['J', 'Q', 'K']:
            return 10
        elif rank == 'A':
            return 11  # Valor por defecto del A
        else:
            return int(rank)

    @property
    def is_ace(self):
      if self.rank == 'A':
         return True
      return False

    def get_value(self):
        return [1, 11] if self.is_ace else [self.value]
    ·
    ·
    ·
```

Para el Factory Method de las clases jugadores:

```python
class Player:
    def __init__(self, name):
        self.name = name
        self.hands = []  # Lista de objetos carta (mano)
        self.deck = self.get_shared_deck()

    def take_card(self):
      carta = self.deck.draw_card()
      if carta not None:
        self.hands.append(carta)

    def get_shared_deck():
        return Deck()  # Obtiene el objeto singleton Deck

    def split_hand(self, index):
        # Lógica para casos de separar manos
        ...
    ·
    ·
    ·

## Implementando Factory method:

class Dealer(Player):
    def __init__(self):
        super().__init__("Dealer")

class ParticipantFactory:
    @staticmethod
    def create_participant(role, name=None):
        if role == "dealer":
            return Dealer()
        elif role == "player":
            return Player(name)
        else:
            raise ValueError("Unknown role")
    ·
    ·
    ·
```

Para implementar el simpleton:

```python
## Implementando Singleton:

class Deck:
    _instance = None # Bandera indicando si existe el original

    # Constructor
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super().__new__(cls)
            cls._instance._initialized = False
        return cls._instance

    # Inicializador
    def __init__(self):
        if self._initialized:
            return
        self.cards = self._create_deck()
        self.shuffle()
        self._initialized = True

    def _create_deck(self):
        suits = ['Hearts', 'Diamonds', 'Clubs', 'Spades']
        ranks = {
            '2': 2, '3': 3, '4': 4, '5': 5, '6': 6,
            '7': 7, '8': 8, '9': 9, '10': 10,
            'J': 10, 'Q': 10, 'K': 10, 'A': 11
        }
        return [Card(suit, rank) for suit in suits for rank in ranks]

    # Mezclar mazo
    def shuffle(self):
        random.shuffle(self.cards)

    # Permitir sacar cartas a los jugadores
    def draw_card(self):
        return self.cards.pop() if self.cards else None
    ·
    ·
    ·
```

## Pregunta 2:

### Solución y patrones propuestos

### Implementación en código


## Pregunta 3:

### Solución y patrones propuestos

### Implementación en código



