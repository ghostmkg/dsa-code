import kotlin.math.*
import kotlin.random.Random

fun main() {
    val hello = "Hello, Kotlin!"
    typewrite("Launching...", 18)
    progressBar("Boot", 28)
    println()
    fancyTitle(hello)
    confetti(24)
    println()
    typewrite("Have a great day 🌈", 20)
}

fun typewrite(text: String, delayMs: Long) {
    for (ch in text) {
        print(ch)
        System.out.flush()
        Thread.sleep(delayMs)
    }
    println()
}

fun progressBar(label: String, totalSteps: Int) {
    for (i in 0..totalSteps) {
        val width = 24
        val filled = ((i / totalSteps.toDouble()) * width).roundToInt().coerceIn(0, width)
        val bar = "█".repeat(filled) + " ".repeat(width - filled)
        val pct = (i * 100) / totalSteps
        print("\r$label [$bar] $pct%")
        System.out.flush()
        Thread.sleep(70)
    }
}

fun fancyTitle(text: String) {
    val colors = listOf(196, 202, 208, 214, 220, 190, 154, 118, 82, 46, 47, 48, 49, 50, 51, 45, 39, 33, 27, 21, 57, 93, 129, 165, 201)
    val pad = 2
    val border = "═".repeat(text.length + pad * 2)
    println("╔$border╗")
    print("║")
    repeat(pad) { print(" ") }
    val step = max(1, colors.size / max(1, text.length))
    for ((idx, ch) in text.withIndex()) {
        val color = colors[min(idx * step, colors.size - 1)]
        print("\u001B[38;5;${color}m$ch\u001B[0m")
    }
    repeat(pad) { print(" ") }
    println("║")
    println("╚$border╝")
}

fun confetti(lines: Int) {
    val symbols = listOf("✨","★","✦","✧","❖","❉","❋","❇","⋆","✺","❀","✿","❁","✾","❂","☼","•","◦","∙","●","○","◆","◇","■","□","▲","△","❣","❤","🎉","🎊","🎈")
    val r = Random(System.currentTimeMillis())
    val width = 48
    repeat(lines) {
        val count = r.nextInt(10, 18)
        val positions = (0 until count).map { r.nextInt(0, width) }.sorted()
        val row = CharArray(width) { ' ' }
        for (pos in positions) {
            val s = symbols[r.nextInt(symbols.size)]
            val fragment = s
            val bytes = fragment.toByteArray().size
            if (pos < width) {
                print("\u001B[38;5;${r.nextInt(16, 231)}m$fragment\u001B[0m")
            }
        }
        println()
        Thread.sleep(40)
    }
}
