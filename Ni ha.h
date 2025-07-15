body {
  font-family: 'Segoe UI', sans-serif;
  background-color: #f0f4ff; /* Azul pastel claro */
  text-align: center;
  margin: 0;
  padding: 20px;
}

h1 {
  color: #5c4d7d; /* Lila oscuro */
  margin-bottom: 30px;
}

.malla {
  display: flex;
  flex-wrap: wrap;
  justify-content: center;
  gap: 20px;
}

.semestre {
  background-color: #e3e7ff; /* Lila muy suave */
  border: 2px solid #b0bdf0;
  border-radius: 10px;
  padding: 10px;
  width: 250px;
}

.semestre h2 {
  color: #4a5280;
  margin-bottom: 10px;
}

.materia {
  background-color: #d2e4f7; /* Azul suave */
  border: 1px solid #87a7d9;
  padding: 10px;
  margin: 5px 0;
  border-radius: 6px;
  cursor: pointer;
  transition: 0.3s;
}

.bloqueada {
  background-color: #eeeeee;
  color: #aaa;
  border-color: #ccc;
  cursor: not-allowed;
}

.aprobada {
  background-color: #d5f3d6;
  border-color: #4caf50;
  color: #2e7d32;
}
