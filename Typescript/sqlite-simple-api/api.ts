import { serve } from "https://deno.land/std@0.65.0/http/server.ts";
import { DB } from "https://deno.land/x/sqlite/mod.ts";

const PORT = 8162;
const s = serve({ port: PORT});

const db = new DB("my.db");
db.query(
  "CREATE TABLE IF NOT EXISTS jobs (\
    id INTEGER PRIMARY KEY AUTOINCREMENT, \
    created_at DATETIME, last_updated DATETIME , \
    active BOOLEAN, company_id INTEGER, apply_url TEXT, \
    job_title CHARACTER(140), details TEXT, pay_range TEXT)"
);
db.query(
  "CREATE TABLE IF NOT EXISTS companies (\
    id INTEGER PRIMARY KEY AUTOINCREMENT, \
    logo_url TEXT, \
    name CHARACTER(50), \
    description TEXT, \
    created_at DATETIME, \
    last_updated DATETIME , \
    active BOOLEAN)"
);
/* db.query(
  "INSERT INTO companies (logo_url, name, description, created_at, last_updated, active) VALUES (?,?,?,?,?,?)",
  ["adresaURL", "Adastra", "popis firmy", Date.now(), Date.now(), 1]
); */


console.log(`Listening on <http://localhost>:${PORT}/`);

for await (const req of s) {
  const params = req.url.split("?");
  const bad_request = { body: "Error 400: bad request.", status: 400 };

  if (params.length > 2) {
    req.respond(bad_request);
    continue;
  }
  const url = params[0];
  const search_params = new URLSearchParams(params[1]);

  if (url == "/api/v1/jobs") {
    let count = 10;
    let request_count = search_params.get("count");

    if (request_count) {
      if (parseInt(request_count) > 100) {
        req.respond(bad_request);
        continue;
      } else {
        count = parseInt(request_count);
      }
    }

    const results = [];
    for (const [
      job_title,
      name,
    ] of db.query(
      "SELECT job_title,name \
        FROM jobs \
        JOIN companies ON company_id = companies.id \
        ORDER BY jobs.id DESC \
        LIMIT ?",
      [count]
      )) {
        results.push({ company_name: name, job_title: job_title });
    }

    req.respond({
      body: JSON.stringify(results),
      status: 200,
    });
    continue;
  }

  if (url == "/api/v1/jobs/add") {
    let password_valid = false;
    const password = "supesecuredpassword";
    let request_password = search_params.get("pw");
    if (request_password) {
      if (request_password == password) {
        password_valid = true;
      }
    }
    if (password_valid == false) {
      req.respond({
        body: "Not Allowed",
        status: 405,
      });
      continue;
    }
    // validated can add
    else {
      const apply_url = search_params.get("apply_url");
      const job_title = search_params.get("job_title");
      const company = search_params.get("company");
      const details = search_params.get("details");
      const pay_range = search_params.get("pay_range");
      let company_id;
      // To get the company ID we need to know if from the other table
      for (const [id] of db.query("SELECT id FROM companies WHERE name = ?", [
        company,
      ]))
        company_id = id;
      // companies are added in a different endpoint
      if (!company_id) {
        req.respond({ body: "Company Name not specified.", status: 400 });
        continue;
      }
      // write into database
      db.query(
        "INSERT INTO jobs (company_id, apply_url, job_title, details, pay_range,created_at,last_updated,active) VALUES (?,?,?,?,?,?,?,?)",
        [company_id, apply_url, job_title, details, pay_range, Date.now(), Date.now(), 1]
      );
      req.respond({
        status: 200,
      });
			continue;
    }
  }
}

db.close();
