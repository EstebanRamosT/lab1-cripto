# ============================================================
# Las clases equivalentes a las de C++
# En Python no hay .h y .cpp, todo va en un solo archivo
# ============================================================

# ---- CriptoMoneda ----
class CriptoMoneda:
    def __init__(self, identificador, nombre):
        self.__identificador = identificador  # privado con __
        self.__nombre = nombre

    def get_identificador(self): return self.__identificador
    def get_nombre(self): return self.__nombre
    def set_identificador(self, id): self.__identificador = id
    def set_nombre(self, nombre): self.__nombre = nombre

    def __str__(self):  # equivalente al operator<< de C++
        return f"{self.__nombre} ({self.__identificador})"


# ---- Transaccion (clase abstracta) ----
from abc import ABC, abstractmethod

class Transaccion(ABC):
    def __init__(self, token, fecha_hora):
        self.__token = token
        self.__fecha_hora = fecha_hora

    @abstractmethod
    def get_tipo(self): pass  # método virtual puro

    def print(self):
        return f"Token: {self.__token} | Fecha: {self.__fecha_hora}"

    def get_token(self): return self.__token
    def get_fecha_hora(self): return self.__fecha_hora


# ---- Enviar y Recibir ----
class Enviar(Transaccion):
    def get_tipo(self): return 1

class Recibir(Transaccion):
    def get_tipo(self): return 2


# ---- Movimiento ----
class Movimiento:
    def __init__(self, moneda, token, fecha_hora, tipo, valor):
        self.__moneda = moneda
        self.__valor = valor
        self.__transaccion = Enviar(token, fecha_hora) if tipo == 1 else Recibir(token, fecha_hora)

    def get_moneda(self): return self.__moneda
    def get_transaccion(self): return self.__transaccion
    def get_valor(self): return self.__valor

    def print(self):
        tipo = "ENVIAR" if self.__transaccion.get_tipo() == 1 else "RECIBIR"
        return f"[{tipo}] Valor: {self.__valor} | {self.__transaccion.print()}"


# ---- Monedero ----
class Monedero:
    def __init__(self):
        self.__monedas = []      # vector<CriptoMoneda>
        self.__movimientos = []  # vector<Movimiento>

    def crear_moneda(self, moneda):
        self.__monedas.append(moneda)

    def ver_monedas(self):
        return self.__monedas

    def editar_moneda(self, identificador, nuevo_nombre):
        for m in self.__monedas:
            if m.get_identificador() == identificador:
                m.set_nombre(nuevo_nombre)
                return True
        return False

    def eliminar_moneda(self, identificador):
        self.__monedas = [m for m in self.__monedas if m.get_identificador() != identificador]

    def enviar_moneda(self, moneda, token, fecha_hora, valor):
        self.__movimientos.append(Movimiento(moneda, token, fecha_hora, 1, valor))

    def recibir_moneda(self, moneda, token, fecha_hora, valor):
        self.__movimientos.append(Movimiento(moneda, token, fecha_hora, 2, valor))

    def calcular_saldos(self):
        saldos = {}
        for moneda in self.__monedas:
            id = moneda.get_identificador()
            saldos[id] = {"moneda": moneda, "saldo": 0.0, "movimientos": []}

        for mov in self.__movimientos:
            id = mov.get_moneda().get_identificador()
            if id in saldos:
                if mov.get_transaccion().get_tipo() == 2:
                    saldos[id]["saldo"] += mov.get_valor()
                else:
                    saldos[id]["saldo"] -= mov.get_valor()
                saldos[id]["movimientos"].append(mov)

        return saldos


# ============================================================
# Interfaz gráfica con tkinter
# ============================================================
import tkinter as tk
from tkinter import ttk, messagebox

class App:
    def __init__(self, root):
        self.root = root
        self.root.title("Monedero de Criptomonedas")
        self.root.geometry("800x600")
        self.monedero = Monedero()
        self._cargar_datos_iniciales()
        self._construir_ui()

    def _cargar_datos_iniciales(self):
        # Las 3 monedas iniciales
        btc = CriptoMoneda("BTC", "Bitcoin")
        eth = CriptoMoneda("ETH", "Ethereum")
        xrp = CriptoMoneda("RIPPLE", "Ripple")
        self.monedero.crear_moneda(btc)
        self.monedero.crear_moneda(eth)
        self.monedero.crear_moneda(xrp)

        # 6 de recibir
        self.monedero.recibir_moneda(btc,  "tok001", "2025-02-19 08:00", 10.0)
        self.monedero.recibir_moneda(btc,  "tok002", "2025-02-19 08:30", 5.0)
        self.monedero.recibir_moneda(eth,  "tok003", "2025-02-19 09:00", 20.0)
        self.monedero.recibir_moneda(eth,  "tok004", "2025-02-19 09:30", 8.0)
        self.monedero.recibir_moneda(xrp,  "tok005", "2025-02-19 10:00", 100.0)
        self.monedero.recibir_moneda(xrp,  "tok006", "2025-02-19 10:30", 50.0)

        # 4 de enviar
        self.monedero.enviar_moneda(btc,  "tok007", "2025-02-19 11:00", 4.0)
        self.monedero.enviar_moneda(eth,  "tok008", "2025-02-19 11:30", 6.0)
        self.monedero.enviar_moneda(xrp,  "tok009", "2025-02-19 12:00", 30.0)
        self.monedero.enviar_moneda(xrp,  "tok010", "2025-02-19 12:30", 20.0)

    def _construir_ui(self):
        # Título
        tk.Label(self.root, text="💰 Monedero de Criptomonedas",
                 font=("Arial", 18, "bold")).pack(pady=10)

        # Pestañas
        self.tabs = ttk.Notebook(self.root)
        self.tabs.pack(fill="both", expand=True, padx=10, pady=5)

        self._tab_monedas()
        self._tab_transacciones()
        self._tab_saldos()

    # ---- Pestaña 1: Monedas ----
    def _tab_monedas(self):
        frame = ttk.Frame(self.tabs)
        self.tabs.add(frame, text="Monedas")

        # Lista de monedas
        self.lista_monedas = tk.Listbox(frame, height=8, font=("Arial", 12))
        self.lista_monedas.pack(fill="x", padx=10, pady=10)
        self._actualizar_lista_monedas()

        # Formulario agregar
        form = tk.LabelFrame(frame, text="Agregar / Editar Moneda", padx=10, pady=10)
        form.pack(fill="x", padx=10, pady=5)

        tk.Label(form, text="Identificador:").grid(row=0, column=0, sticky="w")
        self.entry_id = tk.Entry(form)
        self.entry_id.grid(row=0, column=1, padx=5)

        tk.Label(form, text="Nombre:").grid(row=1, column=0, sticky="w")
        self.entry_nombre = tk.Entry(form)
        self.entry_nombre.grid(row=1, column=1, padx=5)

        tk.Button(form, text="Agregar", command=self._agregar_moneda,
                  bg="#4CAF50", fg="white").grid(row=2, column=0, pady=5)
        tk.Button(form, text="Editar", command=self._editar_moneda,
                  bg="#2196F3", fg="white").grid(row=2, column=1, pady=5)
        tk.Button(form, text="Eliminar seleccionada", command=self._eliminar_moneda,
                  bg="#f44336", fg="white").grid(row=2, column=2, pady=5)

    def _actualizar_lista_monedas(self):
        self.lista_monedas.delete(0, tk.END)
        for m in self.monedero.ver_monedas():
            self.lista_monedas.insert(tk.END, str(m))

    def _agregar_moneda(self):
        id = self.entry_id.get().strip().upper()
        nombre = self.entry_nombre.get().strip()
        if not id or not nombre:
            messagebox.showwarning("Atención", "Completa todos los campos")
            return
        self.monedero.crear_moneda(CriptoMoneda(id, nombre))
        self._actualizar_lista_monedas()
        self.entry_id.delete(0, tk.END)
        self.entry_nombre.delete(0, tk.END)

    def _editar_moneda(self):
        id = self.entry_id.get().strip().upper()
        nombre = self.entry_nombre.get().strip()
        if not id or not nombre:
            messagebox.showwarning("Atención", "Completa todos los campos")
            return
        if self.monedero.editar_moneda(id, nombre):
            self._actualizar_lista_monedas()
        else:
            messagebox.showerror("Error", f"No se encontró la moneda {id}")

    def _eliminar_moneda(self):
        sel = self.lista_monedas.curselection()
        if not sel:
            messagebox.showwarning("Atención", "Selecciona una moneda")
            return
        moneda = self.monedero.ver_monedas()[sel[0]]
        self.monedero.eliminar_moneda(moneda.get_identificador())
        self._actualizar_lista_monedas()

    # ---- Pestaña 2: Transacciones ----
    def _tab_transacciones(self):
        frame = ttk.Frame(self.tabs)
        self.tabs.add(frame, text="Transacciones")

        # Lista de movimientos
        self.lista_movimientos = tk.Listbox(frame, height=10, font=("Arial", 10))
        self.lista_movimientos.pack(fill="both", expand=True, padx=10, pady=10)
        self._actualizar_lista_movimientos()

        # Formulario nueva transacción
        form = tk.LabelFrame(frame, text="Nueva Transacción", padx=10, pady=10)
        form.pack(fill="x", padx=10, pady=5)

        tk.Label(form, text="Moneda (ID):").grid(row=0, column=0, sticky="w")
        self.entry_tx_id = tk.Entry(form)
        self.entry_tx_id.grid(row=0, column=1, padx=5)

        tk.Label(form, text="Valor:").grid(row=0, column=2, sticky="w")
        self.entry_tx_valor = tk.Entry(form)
        self.entry_tx_valor.grid(row=0, column=3, padx=5)

        tk.Label(form, text="Token:").grid(row=1, column=0, sticky="w")
        self.entry_tx_token = tk.Entry(form)
        self.entry_tx_token.grid(row=1, column=1, padx=5)

        tk.Label(form, text="Fecha:").grid(row=1, column=2, sticky="w")
        self.entry_tx_fecha = tk.Entry(form)
        self.entry_tx_fecha.insert(0, "2025-02-19 12:00")
        self.entry_tx_fecha.grid(row=1, column=3, padx=5)

        tk.Button(form, text="Recibir", command=lambda: self._nueva_tx(2),
                  bg="#4CAF50", fg="white").grid(row=2, column=0, pady=5, padx=5)
        tk.Button(form, text="Enviar", command=lambda: self._nueva_tx(1),
                  bg="#f44336", fg="white").grid(row=2, column=1, pady=5, padx=5)

    def _actualizar_lista_movimientos(self):
        self.lista_movimientos.delete(0, tk.END)
        saldos = self.monedero.calcular_saldos()
        for id, data in saldos.items():
            self.lista_movimientos.insert(tk.END, f"--- {data['moneda']} ---")
            for mov in data["movimientos"]:
                self.lista_movimientos.insert(tk.END, "  " + mov.print())

    def _nueva_tx(self, tipo):
        id = self.entry_tx_id.get().strip().upper()
        token = self.entry_tx_token.get().strip()
        fecha = self.entry_tx_fecha.get().strip()
        try:
            valor = float(self.entry_tx_valor.get().strip())
        except:
            messagebox.showerror("Error", "El valor debe ser un número")
            return

        moneda = next((m for m in self.monedero.ver_monedas()
                       if m.get_identificador() == id), None)
        if not moneda:
            messagebox.showerror("Error", f"No existe la moneda {id}")
            return

        if tipo == 1:
            self.monedero.enviar_moneda(moneda, token, fecha, valor)
        else:
            self.monedero.recibir_moneda(moneda, token, fecha, valor)

        self._actualizar_lista_movimientos()
        self._actualizar_saldos()

    # ---- Pestaña 3: Saldos ----
    def _tab_saldos(self):
        frame = ttk.Frame(self.tabs)
        self.tabs.add(frame, text="Saldos")

        tk.Button(frame, text="🔄 Actualizar Saldos",
                  command=self._actualizar_saldos,
                  font=("Arial", 12), bg="#2196F3", fg="white").pack(pady=10)

        self.frame_saldos = tk.Frame(frame)
        self.frame_saldos.pack(fill="both", expand=True, padx=20)
        self._actualizar_saldos()

    def _actualizar_saldos(self):
        for widget in self.frame_saldos.winfo_children():
            widget.destroy()

        saldos = self.monedero.calcular_saldos()
        for id, data in saldos.items():
            saldo = data["saldo"]
            color = "#4CAF50" if saldo >= 0 else "#f44336"
            tk.Label(self.frame_saldos,
                     text=f"{data['moneda']}:  {saldo:.6f} {id}",
                     font=("Arial", 14, "bold"),
                     fg=color).pack(pady=8)


# ============================================================
# Punto de entrada
# ============================================================
if __name__ == "__main__":
    root = tk.Tk()
    app = App(root)
    root.mainloop()