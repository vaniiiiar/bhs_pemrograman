<?php

namespace App\Http\Controllers;

use App\Models\Customer;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\DB;

class CustomerController extends Controller
{
    public function index()
    {
        $data = DB::connection('mysql')->table('customers')->get();
        return response()->json($data, 200);
    }

    public function store(Request $request)
    {
        $this->validate($request, [
            'name' => 'required|string',
            'umur' => 'required|string',
            'member' => 'required|string',

        ]);
        $customer = [
            'name' => $request->input('name'),
            'umur' => $request->input('umur'),
            'member' => $request->input('member'),
            'created_at' => \Carbon\Carbon::now()->toDateTimeString(),
            'updated_at' => \Carbon\Carbon::now()->toDateTimeString(),
        ];
        $id = DB::connection('mysql')->table('customers')->insertGetid($customer);
        $data = DB::connection('mysql')->table('customers')->where('id', $id)->first();
        $response = [
            'message' => 'true',
            'message' => 'Customer Created',
            'date' => $data
        ];
        return response()->json($response, 201);
    }

    public function show($id)
    {
        $data = Customer::find($id);
        if($data) {
            return response()->json([
                'succes' => true,
                'message' => 'Data Retrieve',
                'data' => $data
            ]);
        } else {
            return response()->json([
                'succes' => false,
                'message' => 'Parameter Not Found',
            ]);
        }
    }

    public function edit(Request $request, $id)
    {
        $this->validate($request, [
            'name' => 'required|string',
            'umur' => 'required|string',
            'member' => 'required|string',
        ]);

        $data = Customer::find($id);
        if($data) {
            $data->name = $request->input('name');
            $data->umur = $request->input('umur');
            $data->member = $request->input('member');
            $data->save();
            return response()->json([
                'succes' => true,
                'message' => 'Data Update',
                'Data' => $data
            ]);
        } else {
            return response()->json([
                'success' => true,
                'message' => 'Error Update',  
            ]);
        }   
    }

    public function destroy($id)
    {
        $data = Customer::find($id);
        if($data) {
            $data->delete();
            return response()->json([
                'succes' => true,
                'message' => 'Berhasil Di Hapus',
                'data' => $data
            ]);
        } else {
            return response()->json([
                'succes' => false,
                'message' => 'Parameter Not Found',
            ]);
        }
    }
}