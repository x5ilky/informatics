import java.io.BufferedInputStream

private const val MOD = 998244353L

private class FastScanner {
    private val input = BufferedInputStream(System.`in`)
    private val buffer = ByteArray(1 shl 16)
    private var len = 0
    private var ptr = 0

    private fun readByte(): Int {
        if (ptr >= len) {
            len = input.read(buffer)
            ptr = 0
            if (len <= 0) return -1
        }
        return buffer[ptr++].toInt()
    }

    fun nextInt(): Int {
        var c = readByte()
        while (c <= 32) c = readByte()
        var sgn = 1
        if (c == '-'.code) {
            sgn = -1
            c = readByte()
        }
        var res = 0
        while (c > 32) {
            res = res * 10 + (c - '0'.code)
            c = readByte()
        }
        return res * sgn
    }
}

@JvmInline
value class Mint(val v: Long) {
    operator fun plus(other: Mint): Mint {
        var x = v + other.v
        if (x >= MOD) x -= MOD
        return Mint(x)
    }

    operator fun minus(other: Mint): Mint {
        var x = v - other.v
        if (x < 0) x += MOD
        return Mint(x)
    }

    operator fun times(other: Mint): Mint = Mint(v * other.v % MOD)

    operator fun div(other: Mint): Mint = this * other.inv()

    fun pow(exp: Int): Mint {
        var a = this
        var e = exp.toLong()
        var res = Mint(1)
        while (e > 0) {
            if ((e and 1L) != 0L) res *= a
            a *= a
            e = e shr 1
        }
        return res
    }

    fun inv(): Mint = pow((MOD - 2).toInt())
}

fun main() {
    val fs = FastScanner()
    val M = 310
    val n = fs.nextInt()
    val a = IntArray(n + 1)
    for (i in 1..n) a[i] = fs.nextInt()

    val fac = Array(M + 1) { Mint(1) }
    for (i in 1..M) fac[i] = fac[i - 1] * Mint(i.toLong())

    fun binom(nn: Int, k: Int): Mint {
        if (k > nn) return Mint(0)
        return fac[nn] / fac[k] / fac[nn - k]
    }

    val dp = Array(M + 1) { Array(M + 1) { Mint(0) } }
    val dp2 = Array(M + 1) { Array(M + 1) { Mint(0) } }

    dp[0][0] = Mint(1)
    for (i in 1..M) {
        for (j in i..M) {
            var cur = Mint(0)
            for (k in (i - 1)..(j - 1)) {
                cur += dp[i - 1][k] * binom(j, j - k)
            }
            dp[i][j] = cur
        }
    }

    for (wildCnt in 1..M) {
        for (j in 0..wildCnt) {
            var cnt = Mint(0)
            for (l in j..wildCnt) {
                cnt += dp[j][l] * binom(wildCnt, l) *
                        Mint((n - j).toLong()).pow(wildCnt - l)
            }
            dp2[wildCnt][j] = cnt
        }
    }

    val mex = IntArray(n + 1)
    run {
        val cnt = IntArray(n + 2)
        var m = 0
        for (i in 1..n) {
            if (a[i] < 0) break
            cnt[a[i]]++
            while (cnt[m] > 0) m++
            mex[i] = m
        }
    }

    val excluded = BooleanArray(n + 1)
    var wildCnt = 0

    val out = StringBuilder()
    for (i in 1..n) {
        if (a[i] == -1) {
            wildCnt++
        } else {
            excluded[a[i]] = true
        }

        var k = 0
        var ans = Mint(0)
        for (j in 0..wildCnt) {
            while (excluded[k]) k++
            ans += dp2[wildCnt][j] * Mint(k.toLong())
            k++
        }

        if (wildCnt == 0) out.append(mex[i])
        else out.append(ans.v)
        out.append(' ')
    }

    println(out.toString())
}

// begin signature
// +----------------------------------------+
// |ㇵㇵㇵヘシ丁・シビせせ火ビミ一シシシヘシ|
// |ㇸㇸ・　一火汎労李李労洪允せビシ　　　　|
// |丁ミシせ労耗李労汎允山せせせ火ミ一・ㇵㇵ|
// |山山洪耗和洪允せ山允山せせ火ビミヘ一　ㇵ|
// |労労奏和汎允洪和耗奏奏李洪汎允山火ミㇵ　|
// |群和奏労洪允汎労労労李和耗耗和労汎せミシ|
// |李李李労洪汎汎せ允汎洪洪労李耗群耗労山ビ|
// |汎允允允允允山せ火火火せせ允汎労和奏労允|
// |ビ丁丁丁ビビミ・ㇵシシ　　丁ヘ　洪李和洪|
// |ㇵ一一一ㇵ・一・ㇵシ丁ビビビ丁ㇵ一洪労洪|
// |ㇸ　　　　ㇸㇵシミ丁丁ビせ山山ビヘ　山山|
// |ㇵシシシヘㇵ一一一一一ヘミビ山火ミ一ミミ|
// |ビ火せせ丁ㇵ・・ㇸ一ㇸ　ㇸヘミミシㇵ・ㇸ|
// |允汎汎火シㇸㇸヘミ丁丁ミㇵ　一一ㇵㇵ一・|
// |洪李汎火シ・ㇵ丁火山允山火ミ一・シビビシ|
// |李耗洪火シ　ヘビ允労李李洪山丁ㇵㇸミ丁ㇵ|
// |奏和允ビㇵㇸミ山労耗群群和汎火ヘ　シシ一|
// |耗洪せシ　ヘ火洪耗義覇群和允ビ一ㇸヘシ一|
// |李允丁一一丁允李群慶陽耗洪火ヘ　　ヘㇸㇵ|
// |労山ミㇸㇵビ允李群陽奏労山ミㇸ一ㇵミミヘ|
// +----------------------------------------+
// 2026 (April 7th) 16:26:08
// end signature
