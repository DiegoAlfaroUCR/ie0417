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

Ejemplo de uso:

```python
# Crear el mazo (Singleton)
deck = Deck()

# Crear participantes usando el Factory Method
dealer = ParticipantFactory.create_participant("dealer")
player1 = ParticipantFactory.create_participant("player", name="Alice")
player2 = ParticipantFactory.create_participant("player", name="Bob")

# Repartir dos cartas a cada jugador y al dealer
for _ in range(2):
    player1.take_card()
    player2.take_card()
    dealer.take_card()

# Mostrar las cartas de cada participante
print(f"Cartas de {player1.name}: {[f'{c.rank} de {c.suit}' for c in player1.hands]}")
print(f"Cartas de {player2.name}: {[f'{c.rank} de {c.suit}' for c in player2.hands]}")
print(f"Cartas del Dealer: {[f'{c.rank} de {c.suit}' for c in dealer.hands]}")

```

## Pregunta 2: Diseñar un sistema de compra de entradas de cine

La pregunta, tomada de la página [CodeZym](https://codezym.com/question/10) pero también preguntada en [GeeksforGeeks](https://www.geeksforgeeks.org/design-bookmyshow-a-system-design-interview-question/#how-does-bookmyshow-talk-to-theatres) y [Medium](https://medium.com/@prashant558908/solving-top-10-low-level-design-lld-interview-questions-in-2024-302b6177c869) plantea lo siguiente:

> Diseñe un sistema de compra de entradas de cine como BookMyShow. Incluyendo distintos cines, con multiples salas, donde cada ususario puede comprar varios asientos.

El principal reto del problema es poder manejar la información de manera que esté actualizada a la hora de intentar comprar entradas. El sistema debe tener la capacidad de manejar casos donde se agregan nuevas salas en distintos cines, y la eliminación de campos recientemente comprados. La estructura básica incluiría varias entidades que manejan los campos disponibles, cada cine con sus respectivas salas, los cuales se encargan de guardar la información de los campos disponibles. Luego están los clientes que pueden comprar campos de una sala, estos solo deben poder interactuar con la interfaz de la aplicación, no directamente con los cines. Finalmente, la aplicación debe mantener la información actualizada de cada sala, y debe ser capaz de cambiar la disponibilidad de campos que le muestra a los clientes.

### Solución y patrones propuestos

Se propone el uso del patrón de Observer, el cual es necesario para que la aplicación se mantenga actualizada con la información más reciente. Esta se dará como una clase `ticketApp` que es subscriptora de todos los objetos de la clase `cinema`, los cuales albergan los cambios a los `shows` (películas) y asientos disponibles. Además, están las clases `cliente` las cuales pueden buscar y comprar asientos a travéz de la `ticketApp`. Se considera necesario el uso de este patrón ya que actualizar constantemente la información mostrada por la aplicación sería costoso en término de recursos en runtime, y difícil de implementar conforme crecen la cantidad de cines mostrados en la misma.

### Implementación en código

Código generado en conjunto con modelos de machine learning.

Se crea la clase `show` para las películas contenidas en cada cine. Incluye el nombre de la película y la cantidad de asientos disponibles. Posee un método para reducir la cantidad de asientos disponibles.

```python
class Show:
    def __init__(self, movie_name, seats_available):
        self.movie_name = movie_name
        self.seats_available = seats_available

    def reduce_seat(self):
        if self.seats_available > 0:
            self.seats_available -= 1
            return True
        return False
```

La clase `cinema` incluye una lista de shows y observadores (instancias de la aplicación). Tiene métodos para agregar shows, observadores, notificar a los observadores y actualizar si un asiento fue comprado. Este implementa la lógica del Subject en el patrón observer.

```python
class Cinema:
    def __init__(self, name):
        self.name = name
        self.shows = []
        self.observers = []

    def add_observer(self, observer):
        self.observers.append(observer)

    def notify_observers(self, show, update_type):
        for observer in self.observers:
            observer.update(self.name, show, update_type)

    def add_show(self, movie_name, seats_available):
        show = Show(movie_name, seats_available)
        self.shows.append(show)
        self.notify_observers(show, update_type="new_show")

    def book_seat(self, movie_name):
        for show in self.shows:
            if show.movie_name == movie_name and show.reduce_seat():
                self.notify_observers(show, update_type="seat_booked")
                return True
        return False
```

Luego se agrega la aplicación, la cual se suscribe a las distintas instancias de cines, es actualiza según los cambios hechos y realiza el proceso de comprar un tiquete de parte del cliente. Este implementa la lógica del subscriber en el patrón observer.

```python
class TicketApp(Observer):
    def __init__(self):
        self.show_map = {}  # { cinema_name: [show1, show2, ...] }

    def subscribe_to_cinema(self, cinema):
        cinema.add_observer(self)
        self.show_map[cinema.name] = []

    def update(self, cinema_name, show, update_type):
        if update_type == "new_show":
            self.show_map[cinema_name].append(show)
            print(f"[TicketApp] New show added in {cinema_name}: {show.movie_name}")
        elif update_type == "seat_booked":
            print(f"[TicketApp] A seat was booked in {cinema_name}: {show.movie_name} ({show.seats_available} left)")

    def book_ticket(self, cinema, movie_name):
        print(f"[TicketApp] Attempting to book 1 seat for '{movie_name}' at {cinema.name}")
        return cinema.book_seat(movie_name)
```

Finalmente, se tiene un template básico de la clase `cliente`, esta requiere mayor desarrollo pero da una idea de la lógica del programa.

```python
class Client:
    def __init__(self, name):
        self.name = name

    def book_movie_ticket(self, app: TicketApp, cinema: Cinema, movie_name: str):
        # Logic for selecting a movie and booking a ticket via TicketApp
        pass  # To be implemented
```

Ejemplo de uso:

```python
# Crear componentes del sistema
cinema1 = Cinema("Cineplex")
cinema2 = Cinema("GrandCinema")
app = TicketApp()

# Registrar el app como un observer
app.subscribe_to_cinema(cinema1)
app.subscribe_to_cinema(cinema2)

# Agregar shows
cinema1.add_show("Inception", 5)
cinema2.add_show("Interstellar", 3)

# Crear un cliente que intenta comprar un asiento
client = Client("Alice")
app.book_ticket(cinema1, "Inception")  # Books via app (seat count updates)
```


## Pregunta 3:

### Solución y patrones propuestos

### Implementación en código



