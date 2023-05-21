require("dotenv").config();
const express = require("express");
const cors = require("cors");

const PORT = process.env.PORT;

const app = express();

const fs = require("fs");

app.use(express.json());
// app.use(cors());
app.use((req, res, next) => {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Methods", "GET, PUT, POST");
  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  next();
});

app.post("/testi", (req, res) => {
  fs.writeFile(
    "./client/src/data/data.sqf",
    JSON.stringify(req.body),
    (err) => {
      if (err) {
        console.error(err);
      }
      console.log('write');
    }
  );
  res.send("Kiinnij äiot");
});

app.get("/posteljooni", (req, res) => {
  fs.readFile("./client/src/data/data.sqf", "utf8", (err, data) => {
    if (err) {
      console.error(err);
      return;
    }
    const parsakaali = JSON.parse(data);
    res.json(parsakaali);
  });
});

app.get("/pages", (req, res) => {
  res.send("<b>moro 2</b>");
});

app.listen(PORT, () => {
  console.log(`Server listening on ${PORT}`);
});
