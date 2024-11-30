classDiagram
    class Game {
        -File
        -Grid
        -NbIteration
        +PrintData(): void
        +GetFile(): void
        +UpdateGrid(): void
        +End(): void
    }

    class FileParser {
        -Length
        -Width
        -Size
        +GetSLength(): int
        +GetWidth(): int
        +GetSize(): int
    }

    class FileVerify {
        -SizeOk: bool
        -ValuesOk: bool
        +GetSizeOk(): bool
        +GetValuesOk(): bool
    }

    class Grid {
        -Data: vector
        +CreateGrid(data: Vector): void
        +GetData(): Vector
    }

    class Cells {
        -State: bool
        -Position: String
        +GetState(): bool
        +SetState(state: bool): void
        +GetPosition(): String
    }

    class GridVerify {
        -IsEmpty: bool
        -IsEqual: bool
        +GetIsEmpty(): bool
        +GetIsEqual(): bool
    }

    class Subject {
        +attach(observer: Observer): void
        +detach(observer: Observer): void
        +notify(): void
    }

    class ConcreteSubject {
        -observers: vector<Observer>
        -data: vector<vector<int>>
        +setData(data: vector<vector<int>>): void
        +getData(): vector<vector<int>>
        +attach(observer: Observer): void
        +detach(observer: Observer): void
        +notify(): void
    }

    class Observer {
        +update(data: vector<vector<int>>): void
    }

    class ConsoleObserver {
        +update(data: vector<vector<int>>): void
    }

    class SFMLObserver {
        -cellSize: int
        -window: RenderWindow
        +SFMLObserver(gridSize: int, cellSize: int = 20)
        +update(data: vector<vector<int>>): void
    }

    %% Relations
    Game ..> FileParser : lit le fichier
    FileParser ..> Grid : extrait les données
    FileParser ..> FileVerify : vérifie la validité des données
    Grid <|-- Cells : composent
    Game ..> GridVerify : vérifie les données de la grille
    Game ..> ConcreteSubject : "fournit les données" %% Dépendance
    ConcreteSubject --|> Subject : "hérite de" %% Héritage
    ConcreteSubject o--> Observer : "contient des observateurs" %% Agrégation
    Observer <|-- ConsoleObserver : "implémente" %% Héritage
    Observer <|-- SFMLObserver : "implémente" %% Héritage
    SFMLObserver--> RenderWindow : "contient une instance" %% Composition