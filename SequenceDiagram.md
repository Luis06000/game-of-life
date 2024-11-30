sequenceDiagram
    participant main
    participant Game
    participant FileParser
    participant FileVerify
    participant Grid
    participant GridVerify
    participant Cells
    participant ConcreteSubject
    participant ConsoleObserver
    participant SFMLObserver

    %% Étape 1 : Initialisation
    main ->> Game: create()
    Game ->> FileParser: GetFile()
    FileParser ->> FileVerify: verify(data)
    FileVerify -->> FileParser: validity (SizeOk, ValuesOk)
    FileParser -->> Game: valid data

    %% Étape 2 : Création de la grille
    Game ->> Grid: CreateGrid(data)
    Grid ->> Cells: initialize(state, position)
    Cells -->> Grid: initialized
    Grid -->> Game: grid created

    %% Étape 3 : Vérification de la grille
    Game ->> GridVerify: verify(grid)
    GridVerify -->> Game: status (IsEmpty, IsEqual)

    %% Étape 4 : Mise à jour des cellules
    main ->> Game: UpdateGrid()
    Game ->> Grid: updateCells()
    loop for each Cell
        Grid ->> Cells: checkNeighbors()
        Cells -->> Grid: new state
    end
    Grid -->> Game: grid updated

    %% Étape 5 : Notification des observateurs
    Game ->> ConcreteSubject: setData(grid)
    ConcreteSubject ->> ConcreteSubject: notify()
    ConcreteSubject ->> ConsoleObserver: update(grid)
    ConcreteSubject ->> SFMLObserver: update(grid)

    %% Étape 6 : Affichage des résultats
    ConsoleObserver -->> main: displayed in console
    SFMLObserver -->> main: updated graphical window