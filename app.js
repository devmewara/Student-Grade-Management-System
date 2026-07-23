// Mirrors Student.cpp / Course.cpp — same fields, same calculateGrade() thresholds
const students = []; // each: {rollNo, name, marks[], total, average, grade}

const form = document.getElementById("studentForm");
const message = document.getElementById("message");
const studentsBody = document.getElementById("studentsBody");
const emptyState = document.getElementById("emptyState");
const searchBox = document.getElementById("searchBox");
const showTopBtn = document.getElementById("showTopBtn");
const topResult = document.getElementById("topResult");

function calculateGrade(average) {
    if (average >= 90) return "A+";
    if (average >= 80) return "A";
    if (average >= 70) return "B+";
    if (average >= 60) return "B";
    if (average >= 50) return "C";
    return "F";
}

function gradeClass(grade) {
    return { "A+": "g-Ap", "A": "g-A", "B+": "g-Bp", "B": "g-B", "C": "g-C", "F": "g-F" }[grade];
}

function showMessage(text, type) {
    message.textContent = text;
    message.className = "message " + type;
}

// sortByRank(): same comparator as Course::sortByRank() — descending by total
function sortByRank() {
    students.sort((a, b) => b.total - a.total);
}

function render(filterText = "") {
    sortByRank();
    const query = filterText.trim().toLowerCase();
    const visible = query
        ? students.filter(s => s.name.toLowerCase().includes(query) || String(s.rollNo).includes(query))
        : students;

    studentsBody.innerHTML = "";
    emptyState.style.display = students.length === 0 ? "block" : "none";

    visible.forEach((s) => {
        const rank = students.indexOf(s) + 1;
        const tr = document.createElement("tr");
        tr.innerHTML = `
            <td>#${rank}</td>
            <td>${s.rollNo}</td>
            <td>${s.name}</td>
            <td>${s.total.toFixed(2)}</td>
            <td>${s.average.toFixed(2)}</td>
            <td><span class="grade-badge ${gradeClass(s.grade)}">${s.grade}</span></td>
            <td><button class="remove-btn" data-roll="${s.rollNo}">remove</button></td>
        `;
        studentsBody.appendChild(tr);
    });

    studentsBody.querySelectorAll(".remove-btn").forEach(btn => {
        btn.addEventListener("click", () => {
            const roll = Number(btn.dataset.roll);
            const idx = students.findIndex(s => s.rollNo === roll);
            if (idx !== -1) students.splice(idx, 1);
            render(searchBox.value);
            topResult.innerHTML = "";
        });
    });
}

form.addEventListener("submit", (e) => {
    e.preventDefault();

    const rollNo = Number(document.getElementById("rollNo").value);
    const name = document.getElementById("studentName").value.trim();
    const markIds = ["markEng", "markMath", "markSci", "markCS", "markGK"];
    const marks = markIds.map(id => Number(document.getElementById(id).value));

    if (!name) { showMessage("Please enter a name.", "error"); return; }
    if (marks.some(m => Number.isNaN(m) || m < 0 || m > 100)) {
        showMessage("Each mark must be between 0 and 100.", "error");
        return;
    }
    if (students.some(s => s.rollNo === rollNo)) {
        showMessage(`Roll number ${rollNo} already exists.`, "error");
        return;
    }

    const total = marks.reduce((a, b) => a + b, 0);
    const average = total / marks.length;
    const grade = calculateGrade(average);

    students.push({ rollNo, name, marks, total, average, grade });
    render(searchBox.value);
    showMessage(`${name} added — Total ${total}, Average ${average.toFixed(2)}, Grade ${grade}`, "ok");
    form.reset();
});

searchBox.addEventListener("input", () => render(searchBox.value));

// topNStudents(n) — same logic as Course::topNStudents()
showTopBtn.addEventListener("click", () => {
    sortByRank();
    const n = Math.min(Number(document.getElementById("topN").value) || 0, students.length);
    if (n <= 0) { topResult.innerHTML = ""; return; }

    topResult.innerHTML = students.slice(0, n)
        .map((s, i) => `<div>#${i + 1} — ${s.name} (Roll ${s.rollNo}) — Avg ${s.average.toFixed(2)}, ${s.grade}</div>`)
        .join("");
});

render();
