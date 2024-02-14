## Requirements

-   g++ v.8.2 or newer

## Compilation Steps

1. **Compile Static Library**:

    - Navigate to the `static_library` directory.
    - Run the provided Makefile to compile the static library.

    ```sh
    cd static_library
    make
    ```

2. **Move to Parent Directory**:

    - Move back to the parent directory.

    ```sh
    cd ..
    ```

3. **Compile Application**:

    - Navigate to the `app` directory.
    - Run the provided Makefile to compile the application, linking it with the static library.

    ```sh
    cd app
    make
    ```

## Running the Application

After successful compilation, run the application by executing the generated executable file `app.exe`.
