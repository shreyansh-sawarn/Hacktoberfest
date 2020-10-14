# SQLite simple API

Goal of this project is to use Deno and Typescript and try to create simplest API for SQLite possible. SQLite is database in file that can sit in the same directory or initialized with the start of the app.

You can then use it to run your own SQLite database for any app you need and simply accessing the endpoints you define.

## Hints
<details>
  <summary>How to get started</summary>
  Visit [deno.land](https://deno.land/) to get Deno installed with your prefered way. After that, just run it with `deno run api.ts -A` (because Deno is really playing with security, -A allows all security measures to be eased, see docs for more detail).
</details>
<details>
  <summary>SQLite Library</summary>
  Using [this library](https://deno.land/x/sqlite@v2.3.0) makes whole lot of it easy, the interface is smart and modular for each query you need. Imported with `import { DB } from "https://deno.land/x/sqlite/mod.ts";`
</details>
---
Submitted by [dergyitheron](https://github.com/dergyitheron)
