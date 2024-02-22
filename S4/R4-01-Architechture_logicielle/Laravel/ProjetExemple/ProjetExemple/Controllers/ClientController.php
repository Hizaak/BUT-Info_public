<?php

namespace App\Http\Controllers;
use App\Models\Client;
use Illuminate\Http\Request;

class ClientController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        $clients = Client::latest()->paginate(4);

        return view('clients.index',compact('clients'))
            ->with('i', (request()->input('page', 1) - 1) * 4);
    }

    /**
     * Show the form for creating a new resource.
     */
    public function create()
    {
        return view('clients.create');
    }

    /**
     * Store a newly created resource in storage.
     */
    public function store(Request $request)
    {   // 'numeroclient','nom','email','cartebacaire'
        $request->validate([
            'numeroclient' => 'required',
            'nom' => 'required',
            'email' => 'required',
            'cartebancaire' => 'required',
        ]);

        Client::create($request->all());

        return redirect()->route('clients.index')
                        ->with('success','Client créé avec succès.');
    }

    /**
     * Display the specified resource.
     */
    public function show(string $numeroclient)
    {
        $client=Client::findOrFail($numeroclient);
        return view('clients.show',compact('client'));
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(string $numeroclient)

    {
        $client=Client::findOrFail($numeroclient);
        return view('clients.edit',compact('client'));
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, string $numeroclient)
    {
        $client=Client::findOrFail($numeroclient);
        $request->validate([
            'numeroclient' => 'required',
            'nom' => 'required',
            'email' => 'required',
            'cartebancaire' => 'required',
        ]);
        $client->update($request->all());

        return redirect()->route('clients.index')
                        ->with('success','Client mis à jour avec succès');
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(string $numeroclient)
    {
        $client=Client::findOrFail($numeroclient);
        $client->delete();

        return redirect()->route('clients.index')
                        ->with('success','Client supprimé avec succès');
    }
}
