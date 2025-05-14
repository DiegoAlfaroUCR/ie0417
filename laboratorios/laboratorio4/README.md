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

   El mazo de cartas que se tiene en la mesa debe ser único y accesible a todos los jugadores por medio de los métodos apropiados. Se plantea una clase que emplee **Singleton** para lograr estas características, asegurando que si los objetos jugadores intentan generar un nuevo objeto `Mazo` solo se genere uno nuevo si no existe. En caso de que sean jugadores nuevos uniéndose a la mesa, estos solicitarán cartas al mazo ya existente. Debido a la naturaleza del juego, el objeto Mazo debe proveer métodos que permitan sacar la carta más arriba del mazo, más no permitir acceso de lectura/escritura del mismo. Además debe poseer un método para generar/regenerar el mazo todas las cartas de un mazo real, y con un orden aleatorio.

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

> Diseñe un sistema de compra de entradas de cine como BookMyShow. Incluyendo distintos cines, con multiples salas, donde cada usuario puede comprar varios asientos.

El principal reto del problema es poder manejar la información de manera que esté actualizada a la hora de intentar comprar entradas. El sistema debe tener la capacidad de manejar casos donde se agregan nuevas salas en distintos cines, y la eliminación de campos recientemente comprados. La estructura básica incluiría varias entidades que manejan los campos disponibles, cada cine con sus respectivas salas, los cuales se encargan de guardar la información de los campos disponibles. Luego están los clientes que pueden comprar campos de una sala, estos solo deben poder interactuar con la interfaz de la aplicación, no directamente con los cines. Finalmente, la aplicación debe mantener la información actualizada de cada sala, y debe ser capaz de cambiar la disponibilidad de campos que le muestra a los clientes.

### Solución y patrones propuestos

Se propone el uso del patrón de Observer, el cual es necesario para que la aplicación se mantenga actualizada con la información más reciente. Esta se dará como una clase `ticketApp` que es subscriptora de todos los objetos de la clase `cinema`, los cuales albergan los cambios a los `shows` (películas) y asientos disponibles. Además, están las clases `cliente` las cuales pueden buscar y comprar asientos a travéz de la `ticketApp`. Se considera necesario el uso de este patrón ya que actualizar constantemente la información mostrada por la aplicación sería costoso en término de recursos en runtime, y difícil de implementar conforme crecen la cantidad de cines mostrados en la misma.

### Implementación en código

Código generado en conjunto con modelos de machine learning.

Se crea la clase `show` para las películas contenidas en cada cine. Incluye el nombre de la película y la cantidad de asientos disponibles. Posee un método para reducir la cantidad de asientos disponibles.

```python
# Clase de shows/películas
class Show:
    def __init__(self, movie_name, seats_available):
        self.movie_name = movie_name               # Nombre/identificador
        self.seats_available = seats_available     # Contador de asientos disponibles

    def reduce_seat(self):
        if self.seats_available > 0:
            self.seats_available -= 1
            return True
        return False
```

La clase `cinema` incluye una lista de shows y observadores (instancias de la aplicación). Tiene métodos para agregar shows, observadores, notificar a los observadores y actualizar si un asiento fue comprado. Este implementa la lógica del Subject en el patrón observer.

```python
# Clase que maneja shows disponibles en un cine, es Subject del Observer.
class Cinema:
    def __init__(self, name):
        self.name = name
        self.shows = []
        self.observers = []   # Lista de objetos subscriptores

    # Agrega subscriptores
    def add_observer(self, observer):
        self.observers.append(observer)

    # Notifica subscriptores
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
# Aplicación que observa los cambios en los cines
class TicketApp(Observer):
    def __init__(self):
        self.show_map = {}  # Mapea los shows a sus atributos

    # Subscribe a cines nuevos
    def subscribe_to_cinema(self, cinema):
        cinema.add_observer(self)
        self.show_map[cinema.name] = []

    # Se actualiza según el cambio correspondiente
    def update(self, cinema_name, show, update_type):
        if update_type == "new_show":
            self.show_map[cinema_name].append(show)
            print(f"[TicketApp] New show added in {cinema_name}: {show.movie_name}")
        elif update_type == "seat_booked":
            print(f"[TicketApp] A seat was booked in {cinema_name}: {show.movie_name} ({show.seats_available} left)")

    # Método usado por cliente para comprar asiento
    def book_ticket(self, cinema, movie_name):
        print(f"[TicketApp] Attempting to book 1 seat for '{movie_name}' at {cinema.name}")
        return cinema.book_seat(movie_name)
```

Finalmente, se tiene un template básico de la clase `cliente`, esta requiere mayor desarrollo pero da una idea de la lógica del programa.

```python
# Clase cliente para comprar asientos
class Client:
    def __init__(self, name):
        self.name = name

    def book_movie_ticket(self, app: TicketApp, cinema: Cinema, movie_name: str):
        # Requiere agregar la lógica necesaria para comprar los tiquetes
        pass
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


## Pregunta 3: Diseñar un juego de ajedrez

La pregunta, tomada de [Medium](https://medium.com/@prashant558908/solving-top-10-low-level-design-lld-interview-questions-in-2024-302b6177c869), [CodeZym](https://codezym.com/question/8), [GeeksforGeeks](https://www.geeksforgeeks.org/design-a-chess-game/) y un forum de [LeetCode](https://leetcode.com/discuss/post/124564/amazon-ood-design-a-chess-game-by-mohame-h9bd/) en el que se indica que es una pregunta de entrevista de Amazon, se plantea que:

> Diseñe un juego de ajedrez básico, para un tablero tradicional de 8x8, y las piezas originales.

Este problema tiene amplia dificultad en términos de la lógica de juego, UI y demás, pero para propósitos de análisis de los patrones de diseño se ignoran todos estos y se concentra en la estructura de las clases. Se reconoce que se debe tener un único tablero, objetos para las piezas que permitan los distintos tipos de movimientos, y jugadores.

### Solución y patrones propuestos

En el caso del `tablero`, se requiera que sea único y accesible a todos los jugadores y piezas. Esto podría indicar que un patrón Singleton podría ayudar en el desarrollo, sin embargo debido a que no se requiere agregar jugadores de forma variable, se considera innecesario agregar la lógica extra para generar un singleton, solo se crea una clase cuyo objeto se pasa a ambos jugadores por igual y se le da la función de reiniciar y albergar las piezas. Se debe de encargar de verificar la validez de los movimientos, y si un movimiento elimina a una pieza de forma legal la elimina. Adicionalmente posee funcionalidades como mostrar el tablero o indicarle al objeto jugador cuales piezas le quedan.

Para las clases de las piezas, se consideran dos opciones: La primera es utilizar un patrón **Factory method** donde se tiene la clase base `pieza` la cual contiene los atributos del tipo, color y posición de la pieza, y esta se puede derivar en los 8 distintos tipos de pieza con una misma interfaz pero distintas formas de movimiento. La otra es utilizar un método **Strategy** el cual permita a partir de una misma clase pieza para todas las piezas, escoger la estrategia/tipo de movimiento en la creación de la pieza, cambiándola según corresponda a la pieza. Se considera que esta podría ser más flexible a la hora de considerar cambios de peones a piezas distintas. Además, al ser determinado directamente por el tipo de pieza, es posible realizar cambios de forma dinámica con solo actualizar el ícono (si fuese a ser implementado) y el tipo de movimiento al crear o promover la pieza. Por esto se escoge una clase `pieza` la cual posee los atributos color (para definir a cual jugador pertenece) y tipo (define la estrategia a utilizar), además guarda la estrategia actual para no redefinirla cada vez que se realiza un movimiento.

Finalmente se crea un objeto `jugador` que recibe las piezas que le quedan y pide movimientos directamente al objeto tablero.

### Implementación en código

Código generado en conjunto con modelos de machine learning.

Se implementa el código del tablero, con los metodos prototipo para reiniciar/inicializar el tablero, mover piezas y devolver la lista de piezas disponibles a un jugador.

```python
# Clase para tablero
class Board:
    def __init__(self):
        self.reset_board()

    # Reinicia tablero
    def reset_board(self):
        self.board = [[None for _ in range(8)] for _ in range(8)]
        self._setup_pieces()

    def _setup_pieces(self):
        for col in range(8):
            self.board[1][col] = Piece("black", "pawn")
            self.board[6][col] = Piece("white", "pawn")

    def get_piece(self, position):
        row, col = position
        return self.board[row][col]

    # Revisa si movimiento es válido y lo hace
    def move_piece(self, start_pos, end_pos):
        piece = self.get_piece(start_pos)
        if not piece:
            print("No piece at the starting position.")
            return False

        if not (0 <= end_pos[0] < 8 and 0 <= end_pos[1] < 8):
            print("Move out of board bounds.")
            return False

        if not piece.can_move(start_pos, end_pos, self):
            print("Invalid move for piece type.")
            return False

        target = self.get_piece(end_pos)
        if target:
            if target.color == piece.color:
                print("Cannot capture your own piece.")
                return False
            else:
                print(f"{piece.piece_type.capitalize()} captures {target.piece_type}!")

        self.board[end_pos[0]][end_pos[1]] = piece
        self.board[start_pos[0]][start_pos[1]] = None
        return True

    # Muestra el tablero
    def display(self):
        for row in self.board:
            row_repr = ""
            for piece in row:
                if piece:
                    symbol = piece.piece_type[0].upper() if piece.color == "white" else piece.piece_type[0].lower()
                else:
                    symbol = "."
                row_repr += symbol + " "
            print(row_repr)
        print()

    # Devuelve a jugador las piezas que le quedan
    def get_pieces_by_color(self, color):
        pieces = []
        for row in range(8):
            for col in range(8):
                piece = self.board[row][col]
                if piece and piece.color == color:
                    pieces.append(((row, col), piece))
        return pieces

```

Luego, se aplica el patrón Strategy en las piezas, con una clase base `Piece`, que usa la interfaz de `MoveStrategy` con las estrategias concretas planteadas (solo se plantean algunas, pero se pueden plantear las 8 en la versión final). Se agrega la lógica para definir la estrategia según el tipo, y de actualizarla si se promueve la pieza.

```python
# Clase abstracta/interfaz para las estrategias
class MoveStrategy(ABC):
    @abstractmethod
    def can_move(self, start_pos, end_pos, board):
        pass

# Estrategia concreta para peones
class PawnStrategy(MoveStrategy):
    def can_move(self, start_pos, end_pos, board):
        row_start, col_start = start_pos
        row_end, col_end = end_pos
        direction = -1 if board.get_piece(start_pos).color == "white" else 1
        return col_start == col_end and row_end - row_start == direction

# Estrategia concreta para reinas
class QueenStrategy(MoveStrategy):
    def can_move(self, start_pos, end_pos, board):
        row_start, col_start = start_pos
        row_end, col_end = end_pos
        return (row_start == row_end or col_start == col_end or
                abs(row_end - row_start) == abs(col_end - col_start))
    
# Se deben codificar las demás estrategias
    ·
    ·
    ·

# Clase base para las piezas
class Piece:
    def __init__(self, color, piece_type):
        self.color = color
        self.piece_type = piece_type
        self.strategy = self.set_strategy()

    # Define estrategia según el tipo de pieza
    def set_strategy(self):
        if self.piece_type == "pawn":
            return PawnStrategy()
        elif self.piece_type == "queen":
            return QueenStrategy()
        else:
            raise ValueError("Unsupported piece type")

    # Busca generar el movimiento según la estrategia
    def can_move(self, start_pos, end_pos, board):
        return self.strategy.can_move(start_pos, end_pos, board)

    # Para casos donde la pieza se promueve (peones)
    def promote(self, new_type):
        self.piece_type = new_type
        self.strategy = self.set_strategy()
```

Finalmente, se implementa la clase `Player` de forma prototipo para mostrar que interactúa con las piezas a travez de la clase tablero.

```python
# Clase para jugador
class Player:
    def __init__(self, name, color):
        self.name = name
        self.color = color

    # Prototipo para pedir un movimiento
    def request_move(self):
        start = input(f"{self.name} ({self.color}), enter start position (e.g. 6 0): ")
        end = input("Enter end position (e.g. 5 0): ")
        return tuple(map(int, start.split())), tuple(map(int, end.split()))

    # Prototipo para pedir las piezas disponibles
    # Requiere más lógica para visualizarlas
    def get_pieces_on_board(self, board):
        return board.get_pieces_by_color(self.color)
```

Ejemplo de uso:
```python
def main():
   # Crear tablero y jugadores
    board = Board()
    player_white = Player("Alice", "white")
    player_black = Player("Bob", "black")

    players = [player_white, player_black]
    turn = 0

    # Se muestra tablero y se pide un movimiento para el jugador actual
    while True:
        board.display()
        current_player = players[turn % 2]
        start_pos, end_pos = current_player.request_move()
        if board.move_piece(start_pos, end_pos):
            turn += 1
```


## Reflexión

Es importante denotar que mientras que en algunos casos el uso de uno de los patrones fue obvio, su implementación no es tan directa como se esperó. En la mayoría de los casos pese a que se podía implementar el patrón, no necesariamente era tan esencial para el diseño. Además, en algunos casos es necesario moldear el funcionamiento del resto del código a las particularidades/necesidades del patrón, lo cual implica que no encajaba perfectamente en el problema. Además, mientras que se podían aplicar muchos patrones en un mismo problema, se notó que resulta contraproducente por el costo de implementarlos y asegurar su funcionamiento en conjunto. Fue de mucho mayor valor determinar cuales patrones realmente brindarían un beneficio al programa y solo utilizar esos, a buscar cuantos patrones se podían incluir en la solución. Finalmente, los patrones solo muestran su valor real cuando las aplicaciones poseen escalas variables y altas, porque en ejemplos más básicos puede resultar contraintuitivo que dichas soluciones sean más aptas que las soluciones más simples pero funcionales.