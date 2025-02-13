package com.development.mycppproject

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.development.mycppproject.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    external fun tambahMahasiswa(nama: String, nim: Int, ipk: Float, nilai: FloatArray)
    external fun tampilkanMahasiswa(): String

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.btnTambah.setOnClickListener{
            val nama = binding.inputNama.text.toString()
            val nim = binding.inputNIM.text.toString().toIntOrNull() ?: 0
            val ipk = binding.inputIPK.text.toString().toFloatOrNull() ?: 0.0f
            val nilai = binding.inputIPK.text.toString().toFloatOrNull() ?: 0.0f

            if (nama.isNotEmpty() && nim > 0 && ipk >=0.0) {
                tambahMahasiswa(nama, nim, ipk, nilai)
                binding.inputNama.text.clear()
                binding.inputNIM.text.clear()
                binding.inputIPK.text.clear()
            } else {
                binding.txtData.text = "Data tidak valid"
            }
        }

        binding.btnTampilkan.setOnClickListener{
            val daftarMahasiswa = tampilkanMahasiswa()
            binding.txtData.text = daftarMahasiswa
        }
    }

    companion object {
        init {
            System.loadLibrary("mycppproject")
        }
    }
}