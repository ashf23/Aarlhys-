const materias = [
  // [ID, Nombre, Cuatrimestre, [Prerrequisitos]]
  [1, "Historia Universal", 1, []],
  [2, "Dibujo Técnico", 1, []],
  [3, "Orientación Institucional", 1, []],
  [4, "Precálculo", 1, []],
  [5, "Redacción Castellana", 1, []],
  [6, "Fundamentos del Computador", 1, []],
  [7, "Ética I", 1, []],
  [8, "Inglés Nivel 1-3", 1, []],

  [9, "Cálculo Diferencial", 2, [4]],
  [10, "Física General", 2, [4]],
  [11, "Laboratorio Física General", 2, [10]],
  [12, "Historia Dominicana", 2, [1]],
  [13, "Fundamentos de CAD", 2, [2]],
  [14, "Programación para Mecatrónicos", 2, [6]],
  [15, "Educación Física", 2, []],
  [16, "Ing. de los Materiales Aplicada", 2, [4]],
  [17, "Ética II", 2, [7]],
  [18, "Inglés Nivel 4-6", 2, [8]],

  [19, "Cálculo Integral", 3, [9]],
  [20, "Física Mecánica", 3, [10]],
  [21, "Laboratorio Física Mecánica", 3, [20]],
  [22, "Circuitos Eléctricos I", 3, [9]],
  [23, "Lab. Circuitos Eléctricos I", 3, [22]],
  [24, "Seguridad Industrial", 3, []],
  [25, "Ética III", 3, [17]],
  [26, "Probabilidad y Estadística", 3, [9]],
  [27, "Metrología", 3, [2]],
  [28, "Inglés Nivel 7-9", 3, [18]],

  [29, "Circuitos Eléctricos II", 4, [22]],
  [30, "Lab. Circuitos Eléctricos II", 4, [23]],
  [31, "Electrónica I", 4, [22]],
  [32, "Lab. Electrónica I", 4, [31]],
  [33, "Electrónica Digital", 4, [22]],
  [34, "Lab. Electrónica Digital", 4, [33]],
  [35, "Estática y Dinámica Aplicada", 4, [19, 20]],
  [36, "Física Eléctrica", 4, [20]],
  [37, "Lab. Física Eléctrica", 4, [36]],
  [38, "Inglés Nivel 10-12", 4, [28]],

  [39, "Electrónica II", 5, [31]],
  [40, "Lab. Electrónica II", 5, [32]],
  [41, "Sistemas Digitales", 5, [33]],
  [42, "Controles Automáticos I", 5, [31, 22]],
  [43, "Instrumentación Industrial", 5, [31, 22]],
  [44, "Metodología de la Investigación", 5, [25]],
  [45, "Administración de Proyectos", 5, [25]],
  [46, "CAD Avanzado", 5, [13]],
  [47, "Inglés Técnico", 5, [38]],

  [48, "Electrónica Industrial", 6, [39]],
  [49, "Lab. Electrónica Industrial", 6, [40]],
  [50, "Fundamentos de Máquinas Eléctricas", 6, [42]],
  [51, "Controles Automáticos II", 6, [42]],
  [52, "Microcontroladores", 6, [39, 41]],
  [53, "Procesos de Manufactura", 6, [46, 26]],
  [54, "Desarrollo de Emprendedores", 6, [44]],
  [55, "Sistemas de Control", 6, [39, 42, 51]],

  [56, "Integración de Sistemas Mecatrónicos", 7, [42, 50]],
  [57, "Robótica", 7, [48, 52]],
  [58, "Redes de Comunicación Industrial", 7, [55]],
  [59, "Proyecto Final", 7, [42, 50]],
  [60, "Programación Básica CNC", 7, [48, 52]],
  [61, "Plan de Negocios", 7, [54]],
  [62, "Electiva", 7, []],
];

// Carga estado guardado
const estado = JSON.parse(localStorage.getItem("estadoMateriasMec") || "{}");
const contenedor = document.getElementById("malla");

for (let periodo = 1; periodo <= 7; periodo++) {
  const divSem = document.createElement("div");
  divSem.className = "semestre";
  divSem.innerHTML = `<h2>Período ${periodo}</h2>`;

  materias.filter(m => m[2] === periodo).forEach(m => {
    const divMat = document.createElement("div");
    divMat.id = `mat-${m[0]}`;
    divMat.className = "materia bloqueada";
    divMat.textContent = m[1];

    const guardado = estado[m[0]];
    if (guardado === "aprobada") {
      divMat.classList.remove("bloqueada");
      divMat.classList.add("aprobada");
    } else if (guardado === "disponible" || m[3].length === 0) {
      divMat.classList.remove("bloqueada");
    }

    divMat.onclick = () => alternarEstado(m[0]);
    divSem.appendChild(divMat);
  });

  contenedor.appendChild(divSem);
}

function alternarEstado(id) {
  const el = document.getElementById(`mat-${id}`);
  const actual = el.classList.contains("aprobada");

  if (actual) {
    el.classList.remove("aprobada");
    estado[id] = "disponible";
  } else {
    el.classList.add("aprobada");
    estado[id] = "aprobada";
  }

  materias.forEach(m => {
    const requisitos = m[3];
    const puedeDesbloquear = requisitos.every(rid =>
      document.getElementById(`mat-${rid}`).classList.contains("aprobada")
    );
    if (puedeDesbloquear || requisitos.length === 0) {
      document.getElementById(`mat-${m[0]}`).classList.remove("bloqueada");
      if (!estado[m[0]]) estado[m[0]] = "disponible";
    }
  });

  localStorage.setItem("estadoMateriasMec", JSON.stringify(estado));
}
